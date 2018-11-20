import ast
import base64
import sys

MESSAGE = '''GU4AHQwaBxwAT1JbQk4UGgoYFkhfSFUCDQUfDQ4eFwpUSEhBRQwAHAocDwoXT15BRQwVDgALFhxU SEhBRQAdCx0cBgYRBBdGTklUCQwRCwoFDR8EDB1USFVZRRodBB0CCQwXT0NZRR0SChAIFhpUSFVZ RRwSDhdGTklUDgAWRU9JSFUWCwdSTxI='''
KEY = 'bishoyboshra'

#for i, c in enumerate(base64.b64decode(MESSAGE)):
#    sys.stdout.write(chr(ord(c) ^ ord(KEY[i % len(KEY)])))

message = ast.literal_eval(
  ''.join(
    [(chr(ord(c) ^ ord(KEY[i % len(KEY)])))
    for i, c in enumerate(base64.b64decode(MESSAGE))]
  )
)

for k, v in message.iteritems():
  print('%s: %s' % (k, v))

