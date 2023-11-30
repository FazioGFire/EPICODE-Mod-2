programLoop = 'y'

while 'y' in programLoop or 's' in programLoop or 'si' in programLoop:
    print("Ciao, benvenuto in sto schifo. Che figura vuoi rappresentare?")
    userInput = input()

    if 'qu' in userInput:
        print("Stiamo a calcolare il quadrato. Damme il lato:")
        lato = int(input())
        print("L'area del quadrato è: " + str(lato*lato) + ". Il perimetro del rettangolo è: " + str(lato*4))

    elif 'ret' in userInput:
        print("Stiamo a fare il rettangolo. Damme la base")
        base = int(input())
        print("Mo damme l'altezza")
        altezza = int(input())
        print("L'area del rettangolo è:" +  str(base*altezza) + ". Il perimetro è:" +  str((base*2)+(altezza*2)) + ".")

    elif 'cer' in userInput:
        print("Forse facciamo il cerchio. Damme il raggio.")
        raggio = int(input())
        pi = 3.14
        print("Il diametro del cerchio è: " + str((raggio*raggio)*pi) + ". la circonferenza del cerchio è: " + str(2*pi*(raggio*raggio)) + ".")

    else:
        print("zio non so che dici")
        break

    print("Vuoi fare un altro calcolo, zio? si/yes per confermare")
    programLoop = input()

print("ciao.")
