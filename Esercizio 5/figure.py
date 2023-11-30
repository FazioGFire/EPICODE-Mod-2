programLoop = 'y'

while 'y' in programLoop or 's' in programLoop or 'si' in programLoop:
    userInput = input("Ciao, benvenuto in sto schifo. Che figura vuoi rappresentare?")

    if 'qu' in userInput:
        lato = int(input("Stiamo a calcolare il quadrato. Damme il lato:"))
        print("L'area del quadrato è: " + str(lato*lato) + ". Il perimetro del rettangolo è: " + str(lato*4))

    elif 're' in userInput:
        base = int(input("Stiamo a fare il rettangolo. Damme la base"))
        altezza = int(input("Mo damme l'altezza"))
        print("L'area del rettangolo è:" +  str(base*altezza) + ". Il perimetro è:" +  str((base*2)+(altezza*2)) + ".")

    elif 'cer' in userInput:
        raggio = int(input("Forse facciamo il cerchio. Damme il raggio."))
        pi = 3.14
        print("Il diametro del cerchio è: " + str((raggio*raggio)*pi) + ". la circonferenza del cerchio è: " + str(2*pi*(raggio*raggio)) + ".")

    else:
        print("zio non so che dici")
        break

    programLoop = input("Vuoi fare un altro calcolo, zio? si/yes per confermare")

print("ciao.")
