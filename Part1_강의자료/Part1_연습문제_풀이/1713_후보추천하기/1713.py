class student:
    def __init__(self, number, scr, posted_at):
        self.number = number
        self.scr = scr
        self.posted_at = posted_at

N = int(input())
R = int(input())
voted_number_list = list(map(int,input().split()))
post = []

for i in range(R):
    already_posted = False
    
    for j in range(len(post)):
        if post[j].number == voted_number_list[i]:
            post[j].scr += 1
            already_posted = True
            break
    
    if not already_posted:
        if len(post) < N:
            post.insert(0, student(voted_number_list[i], 1, i))
        else:
            post.sort(key=lambda s: (s.scr, s.posted_at))
            post[0] = student(voted_number_list[i], 1, i)

post.sort(key=lambda s: s.number)
print(' '.join(str(s.number) for s in post))
