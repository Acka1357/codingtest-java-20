class Student:
    def __init__(self, number, scr, postedAt):
        self.number = number
        self.scr = scr
        self.postedAt = postedAt

N = int(input())
R = int(input())
votedNumberList = list(map(int,input().split()))
post = []

for i in range(R):
    alreadyPosted = False
    
    for j in range(len(post)):
        if post[j].number == votedNumberList[i]:
            post[j].scr += 1
            alreadyPosted = True
            break
    
    if not alreadyPosted:
        if len(post) < N:
            post.insert(0, Student(votedNumberList[i], 1, i))
        else:
            post.sort(key=lambda s: (s.scr, s.postedAt))
            post[0] = Student(votedNumberList[i], 1, i)

post.sort(key=lambda s: s.number)
print(' '.join(str(s.number) for s in post))
