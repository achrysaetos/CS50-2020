#Coleman-Liau reading level index again, using python

text = input("Text: ")
letters=0
spaces=0
sentences=0
misc=0

for x in text:
    if x==" ":
        spaces+=1
    elif x=="." or x=="!" or x=="?":
        sentences+=1
    elif x==";" or x==":" or x=="," or x=="'" or x=="-":
        misc+=1
    else:
        letters+=1

print("letters: "+str(letters))
print("words: "+str(spaces))
print("sentences: "+str(sentences))
index = round((.0588*(letters-1)/(spaces+1)*100 - .296*sentences/(spaces+1)*100 - 15.8))
if index<1:
    print("GRADE LEVEL: 1")
elif index<16:
    print("GRADE LEVEL: "+str(index))
else:
    print("GRADE LEVEL: 16+")

#TEST CASES
#One fish. Two fish. Red fish. Blue fish. (Before Grade 1)
#Would you like them here or there? I would not like them here or there. I would not like them anywhere. (Grade 2)
#Congratulations! Today is your day. You're off to Great Places! You're off and away! (Grade 3)
#Harry Potter was a highly unusual boy in many ways. For one thing, he hated the summer holidays more than any other time of year. For another, he really wanted to do his homework, but was forced to do it in secret, in the dead of the night. And he also happened to be a wizard. (Grade 5)
#In my younger and more vulnerable years my father gave me some advice that I've been turning over in my mind ever since. (Grade 7)
#Alice was beginning to get very tired of sitting by her sister on the bank, and of having nothing to do: once or twice she had peeped into the book her sister was reading, but it had no pictures or conversations in it, "and what is the use of a book," thought Alice "without pictures or conversation?" (Grade 8)
#When he was nearly thirteen, my brother Jem got his arm badly broken at the elbow. When it healed, and Jem's fears of never being able to play football were assuaged, he was seldom self-conscious about his injury. His left arm was somewhat shorter than his right; when he stood or walked, the back of his hand was at right angles to his body, his thumb parallel to his thigh. (Grade 8)
#There are more things in Heaven and Earth, Horatio, than are dreamt of in your philosophy. (Grade 9)
#It was a bright cold day in April, and the clocks were striking thirteen. Winston Smith, his chin nuzzled into his breast in an effort to escape the vile wind, slipped quickly through the glass doors of Victory Mansions, though not quickly enough to prevent a swirl of gritty dust from entering along with him. (Grade 10)
#A large class of computational problems involve the determination of properties of graphs, digraphs, integers, arrays of integers, finite families of finite sets, boolean formulas and elements of other countable domains. (Grade 16+)