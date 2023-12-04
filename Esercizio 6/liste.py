def w7d1e1():
    inputList = []
    elemList = int(input("Inserisci lunghezza lista"))
    outputList = [5]*elemList

    for i in range(0, elemList):
        elem = str(input("Inserisci una parola: "))
        inputList.append(elem)

    for i in range(len(inputList)):
        #print(str(len(inputList[i])))
        outputList[i] = int(len(inputList[i]))


    print("La lista è: ", outputList )



w7d1e1()
