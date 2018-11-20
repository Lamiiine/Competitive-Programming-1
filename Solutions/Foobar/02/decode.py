import base64
import sys

MESSAGE = '''GU4AHQwaBxwAT1JbGRIFGxYJG15OT1QLHQ1VUAMOBg1IWVhPVA0BFVxQDwwXT0NZRQoVDh0TTUZF SUlISBAMDAENFghbWQdOX0hIGAEHGg0EBFRQDB1USFVZRRodBB0CUlAGTl9ISAsDDREBBhIeFVhJ VBsOHwdIX0hVB1ZaRUlJSEgOCwFSTw8='''
KEY = 'bishoyboshra95'

for i, c in enumerate(base64.b64decode(MESSAGE)):
    sys.stdout.write(chr(ord(c) ^ ord(KEY[i % len(KEY)])))

