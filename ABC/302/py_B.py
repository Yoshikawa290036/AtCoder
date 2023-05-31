# -*- coding: utf-8 -*-


h, w = map(int, input().split())
ss = []
key = 'snuke'

for _ in range(h):
    s = input().strip()
    ss.append(s)

dx = [0, 0, 1, 1, 1, -1, -1, -1]
dy = [1, -1, 1, 0, -1, 1, 0, -1]


def search(si, sj):
    for l in range(8):
        x = si
        y = sj
        for k in range(1, len(key)):
            x = x + dx[l]
            y = y + dy[l]
            if x < 0 or x >= h or y < 0 or y >= w \
                    or ss[x][y] != key[k]:
                break
        else:
            x = si
            y = sj
            for k in range(len(key)):
                print('{} {}'.format(x+1, y+1))
                x = x + dx[l]
                y = y + dy[l]
            exit()

    # for k in range(1, len(key)):
    #     x = si
    #     y = sj + k
    #     if x >= 0 and x < w and y >= 0 and y < h and \
    #             ss[x][y] != key[k]:
    #         break
    # else:
    #     for k in range(len(key)):
    #         x = si
    #         y = sj + k
    #         print('{} {}'.format(si+1, (sj+k) % w+1))
    #     return

    # for k in range(1, len(key)):
    #     if ss[si][(sj-k+w) % w] != key[k]:
    #         break
    # else:
    #     for k in range(len(key)):
    #         print('{} {}'.format(si+1, (sj-k+w) % w + 1))
    #     return

    # for k in range(1, len(key)):
    #     if ss[(si+h+k) % h][sj] != key[k]:
    #         break
    # else:
    #     for k in range(len(key)):
    #         print('{} {}'.format((si+h+k) % h+1, sj+1))
    #     return

    # for k in range(1, len(key)):
    #     if ss[(si+h-k) % h][sj] != key[k]:
    #         break
    # else:
    #     for k in range(len(key)):
    #         print('{} {}'.format((si+h-k) % h+1, sj+1))
    #     return

    # for k in range(1, len(key)):
    #     if ss[(si+h+k) % h][(sj+w+k) % w] != key[k]:
    #         break
    # else:
    #     for k in range(len(key)):
    #         print('{} {}'.format((si+h+k) % h+1, (sj+w+k) % w+1))
    #     return

    # for k in range(1, len(key)):
    #     if ss[(si+h-k) % h][(sj+w+k) % w] != key[k]:
    #         break
    # else:
    #     for k in range(len(key)):
    #         print('{} {}'.format((si+h-k) % h+1, (sj+w+k) % w+1))
    #     return

    # for k in range(1, len(key)):
    #     if ss[(si+h+k) % h][(sj+w-k) % w] != key[k]:
    #         break
    # else:
    #     for k in range(len(key)):
    #         print('{} {}'.format((si+h+k) % h+1, (sj+w-k) % w+1))
    #     return

    # for k in range(1, len(key)):
    #     if ss[(si+h-k) % h][(sj+w-k) % w] != key[k]:
    #         break
    # else:
    #     for k in range(len(key)):
    #         print('{} {}'.format((si+h-k) % h+1, (sj+w-k) % w+1))
    #     return


for i in range(h):
    for j in range(w):
        if ss[i][j] == key[0]:
            search(i, j)
