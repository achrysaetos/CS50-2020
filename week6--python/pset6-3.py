#Luhn's algorithm again, using python
import math

numString = input("number? ")
number = int(numString)
sum1=0
sum2=0

for x in range(1,1+len(numString)):
    if x%2==1:
        sum2 += number%10
        number = math.floor(number/10)
    elif 2*(number%10)<10:
        sum1 += 2*(number%10)
        number = math.floor(number/10)
    else:
        sum1 += math.floor((2*(number%10))/10)+(2*(number%10))%10
        number = math.floor(number/10)

if (sum1+sum2)%10==0:
    number = int(numString)
    if math.floor(number/10000000000000)==34 or math.floor(number/10000000000000)==37:
        print("AMEX")
    elif math.floor(number/100000000000000)==51 or math.floor(number/100000000000000)==52 or math.floor(number/100000000000000)==53 or math.floor(number/100000000000000)==54 or math.floor(number/100000000000000)==55:
        print("MASTERCARD")
    elif math.floor(number/1000000000000000)==4 or math.floor(number/1000000000000)==4:
        print("VISA")
else:
    print("INVALID")

#TEST CASES
#Type in 378282246310005 and press enter. Your program should output AMEX.
#Type in 371449635398431 and press enter. Your program should output AMEX.
#Type in 5555555555554444 and press enter. Your program should output MASTERCARD.
#Type in 5105105105105100 and press enter. Your program should output MASTERCARD.
#Type in 4111111111111111 and press enter. Your program should output VISA.
#Type in 4012888888881881 and press enter. Your program should output VISA.
#Type in 1234567890 and press enter. Your program should output INVALID.