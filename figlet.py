import sys
from pyfiglet import Figlet
import random

if len(sys.argv) == 1:
    isRandom = True
elif len(sys.argv) == 3 and (sys.argv[1] == "-f" or sys.argv[1] == "--font"):
    isRandom = False
else:
    print("usage: 2 or 0 command line arguments")
    sys.exit(1)

figlet = Figlet()

if isRandom == False:
    try:
        figlet.setFont(font=sys.argv[2])
    except:
        print("Font error")
        sys.exit(1)
else:
    figlet.setFont(font=random.choice(figlet.getFonts()))

answer = input("Input: ")
print(f"output: {figlet.renderText(answer)}")
