import sys
input = sys.stdin.readline

N = int(input())
books = {}

for _ in range(N):
    book = input()
    if book in books:
        books[book] += 1
    else:
        books[book] = 1

print(min(books, key=lambda x: (-books[x], x)), end='')
