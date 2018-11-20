'''
Bringing a Gun to a Guard Fight
===============================

Uh-oh - you've been cornered by one of Commander Lambdas elite guards! Fortunately, you grabbed a beam weapon from an abandoned guardpost while you were running through the station, so you have a chance to fight your way out. But the beam weapon is potentially dangerous to you as well as to the elite guard: its beams reflect off walls, meaning youll have to be very careful where you shoot to avoid bouncing a shot toward yourself!

Luckily, the beams can only travel a certain maximum distance before becoming too weak to cause damage. You also know that if a beam hits a corner, it will bounce back in exactly the same direction. And of course, if the beam hits either you or the guard, it will stop immediately (albeit painfully). 

Write a function answer(dimensions, your_position, guard_position, distance) that gives an array of 2 integers of the width and height of the room, an array of 2 integers of your x and y coordinates in the room, an array of 2 integers of the guard's x and y coordinates in the room, and returns an integer of the number of distinct directions that you can fire to hit the elite guard, given the maximum distance that the beam can travel.

The room has integer dimensions [1 < x_dim <= 1000, 1 < y_dim <= 1000]. You and the elite guard are both positioned on the integer lattice at different distinct positions (x, y) inside the room such that [0 < x < x_dim, 0 < y < y_dim]. Finally, the maximum distance that the beam can travel before becoming harmless will be given as an integer 1 < distance <= 10000.

For example, if you and the elite guard were positioned in a room with dimensions [3, 2], you_position [1, 1], guard_position [2, 1], and a maximum shot distance of 4, you could shoot in seven different directions to hit the elite guard (given as vector bearings from your location): [1, 0], [1, 2], [1, -2], [3, 2], [3, -2], [-3, 2], and [-3, -2]. As specific examples, the shot at bearing [1, 0] is the straight line horizontal shot of distance 1, the shot at bearing [-3, -2] bounces off the left wall and then the bottom wall before hitting the elite guard with a total shot distance of sqrt(13), and the shot at bearing [1, 2] bounces off just the top wall before hitting the elite guard with a total shot distance of sqrt(5).

Languages
=========

To provide a Python solution, edit solution.py
To provide a Java solution, edit solution.java

Test cases
==========

Inputs:
    (int list) dimensions = [3, 2]
    (int list) captain_position = [1, 1]
    (int list) badguy_position = [2, 1]
    (int) distance = 4
Output:
    (int) 7

Inputs:
    (int list) dimensions = [300, 275]
    (int list) captain_position = [150, 150]
    (int list) badguy_position = [185, 100]
    (int) distance = 500
Output:
    (int) 9

Use verify [file] to test your solution and see how it does. When you are finished editing your code, use submit [file] to submit your answer. If your solution passes the test cases, it will be removed from your home folder.
'''

'''
represent one instance of the reflection of either
the captain or the badguy
'''
class Point:
    def __init__(self, x, y, bad):
        self.x = x
        self.y = y
        self.bad = bad
    def quadrant(self):
        return (1 if self.y >= 0 else 4) if self.x >= 0 else (2 if self.y >= 0 else 3)
    def cross(self, other):
        return self.x * other.y - self.y * other.x
    def sameVector(self, other):
        return self.quadrant() == other.quadrant() and self.cross(other) == 0
    def sub(self, other):
        return Point(self.x - other.x, self.y - other.y, self.bad)
    def sqrDistance(self, other):
        dx = self.x - other.x
        dy = self.y - other.y
        return dx * dx + dy * dy

def int_compare(a, b):
    return 0 if a == b else (-1 if a < b else 1)

def compare(a, b):
    aq = a.quadrant()
    bq = b.quadrant()
    if aq != bq:
        return int_compare(aq, bq)
    c = a.cross(b)
    if c != 0:
        return int_compare(0, c)
    if abs(a.x) != abs(b.x):
        return int_compare(abs(a.x), abs(b.x))
    if abs(a.y) != abs(b.y):
        return int_compare(abs(a.y), abs(b.y))
    return int_compare(1 if a.bad else 0, 1 if b.bad else 0)

points = []
sqrDistance = 0
captain = Point(0, 0, False)
badguy = Point(0, 0, True)
width = 0
height = 0

num_x = 0
num_y = 0

def generate_row(start):
    points.append(start)
    x = start.x + 2 * width
    for i in range(0, num_x, 2):
        points.append(Point(x, start.y, start.bad))
        x += 2 * width
    x = start.x - 2 * width
    for i in range(0, num_x, 2):
        points.append(Point(x, start.y, start.bad))
        x -= 2 * width

def generate_column(start):
    generate_row(start)
    y = start.y + 2 * height
    for i in range(0, num_y, 2):
        generate_row(Point(start.x, y, start.bad))
        y += 2 * height
    y = start.y - 2 * height
    for i in range(0, num_y, 2):
        generate_row(Point(start.x, y, start.bad))
        y -= 2 * height

def generate(start):
    generate_column(Point(start.x, start.y, start.bad))
    generate_column(Point(-start.x, start.y, start.bad))
    generate_column(Point(start.x, -start.y, start.bad))
    generate_column(Point(-start.x, -start.y, start.bad))

def answer(dimensions, captain_position, badguy_position, distance):
    global width
    width = dimensions[0]
    global height
    height = dimensions[1]
    global captain
    captain = Point(captain_position[0], captain_position[1], False)
    global badguy
    badguy = Point(badguy_position[0], badguy_position[1], True)
    global sqrDistance
    sqrDistance = distance * distance
    global num_x
    num_x = distance / width + 5
    global num_y
    num_y = distance / height + 5
    global points
    points = []
    generate(captain)
    generate(badguy)
    points = sorted([s.sub(captain) for s in points if s.sqrDistance(captain) <= sqrDistance], cmp = compare)
    ans = 0
    i = 1
    while i < len(points):
        cur = points[i]
        if cur.bad:
            ans += 1
        while i < len(points) and cur.sameVector(points[i]):
            i += 1
    return ans
