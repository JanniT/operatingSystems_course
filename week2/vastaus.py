#https://wiki.python.org/moin/BitwiseOperators

def bittisumma(a, b):

    # Alustetaan muuttujat bittiaritmetiikan keinoin
    summa = a ^ b   #"XOR"
    carLuku = (a & b) << 1  #"AND", sekä vasemmalle siirto

    while (carLuku != 0):
        a = summa
        b = carLuku

        summa = a ^ b
        carLuku = (a & b) << 1        

    return summa

# print(bittisumma(5,7)) #Tulos: 12
# print(bittisumma(10,20)) #Tulos: 30
# print(bittisumma(15,17)) #Tulos: 32