import string
import random

def pwdGen():
    choice = input("Vuoi una password semplice o una complessa? s/c, 0,1, semplice/complessa")

    if 'sem' in choice or 's' in choice or '0' in choice:
        pwd = ''.join([random.choice(string.ascii_letters + string.digits) for i in range (8)])
    else:
        pwd = ''.join([random.choice(string.ascii_letters + string.digits + string.punctuation) for n in range (20)])

    print(pwd)

pwdGen()
