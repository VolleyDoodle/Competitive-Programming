import pygame
import random

pygame.init()
screen = pygame.display.set_mode((800, 800))
pygame.display.set_caption("Simple Snake")
start = True

game = False

head_image = pygame.image.load("snake/snake_head.png")
head_image = pygame.transform.scale(head_image, (64, 64))
head_image = pygame.transform.rotate(head_image, -90)
up = False
down = False
right = True
left = False

#print(head_image.get_size())

head_rect = head_image.get_rect(topleft=(400, 400))
#print(head_rect)
past_head_pos = []


food = False
food_surf = pygame.Surface((64, 64), pygame.SRCALPHA)
pygame.draw.circle(food_surf, "red", (32, 32), 16)
food_rect = food_surf.get_rect(topleft=(600, 400))


clone_image = pygame.image.load("snake/snake_body.png")
clone_image = pygame.transform.scale(clone_image, (64, 64))
clone_cnt = 0
#rect also stores pos w/ left and top
#clone_rect = []


score = -1
score_surf = pygame.font.Font(None, 36).render("Score: " + str(clone_cnt), True, "black")
score_rect = score_surf.get_rect(topleft=(10, 10))  


play_surf = pygame.Surface((400, 200))
play_surf.fill("orange")
play_rect = play_surf.get_rect(center = (400, 400))

text = pygame.font.Font(None, 112).render('Play', True, "purple")
text_rect = text.get_rect(center=play_rect.center)

clock = pygame.time.Clock()
screen.fill("white")


def checkCollide(food_rect, cur_rects):
    return any(food_rect.colliderect(rect) for rect in cur_rects)


def outside(head_rect):
    return head_rect.left < -32 or head_rect.right > 832 or head_rect.top < -32 or head_rect.bottom > 832


def gameOver(up, down, right, left, head_rect, cur_rects):
    if up:
        point1 = (head_rect.left, head_rect.top)
        point2 = (head_rect.right, head_rect.top)
    elif down:
        point1 = (head_rect.left, head_rect.bottom)
        point2 = (head_rect.right, head_rect.bottom)
    elif right:
        point1 = (head_rect.right, head_rect.top)
        point2 = (head_rect.right, head_rect.bottom)
    else:
        point1 = (head_rect.left, head_rect.top)
        point2 = (head_rect.left, head_rect.bottom)
    return outside(head_rect) or any(
        rect.collidepoint(point1) or rect.collidepoint(point2)
        for rect in cur_rects)

def gameScreen(up, down, right, left, head_image, past_head_pos, food_rect, clone_cnt, start, game, score):
    cur_rects = []
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            pygame.quit()
            exit()
        if event.type == pygame.KEYDOWN:
            if (event.key == pygame.K_DOWN) and (right or left):
                if right:
                    head_image = pygame.transform.rotate(head_image, -90)
                else:
                    head_image = pygame.transform.rotate(head_image, 90)
                down = True
                right = False
                left = False
            elif (event.key == pygame.K_UP) and (right or left):
                if right:
                    head_image = pygame.transform.rotate(head_image, 90)
                else:
                    head_image = pygame.transform.rotate(head_image, -90)
                up = True
                right = False
                left = False
            elif (event.key == pygame.K_LEFT) and (up or down):
                if up:
                    head_image = pygame.transform.rotate(head_image, 90)
                else:
                    head_image = pygame.transform.rotate(head_image, -90)
                left = True
                up = False
                down = False
            elif (event.key == pygame.K_RIGHT) and (up or down):
                if up:
                    head_image = pygame.transform.rotate(head_image, -90)
                else:
                    head_image = pygame.transform.rotate(head_image, 90)
                right = True
                up = False
                down = False

    for x in range(4):
        if up:
            head_rect.top -= 16 / 2
        elif down:
            head_rect.top += 16 / 2
        elif right:
            head_rect.left += 16 / 2
        elif left:
            head_rect.left -= 16 / 2
        if (x == 1):
            past_head_pos.append((head_rect.left, head_rect.top))

    screen.fill("white")
    score_surf = pygame.font.Font(None, 36).render("Score: " + str(clone_cnt), True, "black")
    screen.blit(score_surf, score_rect)

    for i in range(clone_cnt):
        cRect = clone_image.get_rect(
            topleft=(past_head_pos[len(past_head_pos) - (5 * i) - 5][0],
                     past_head_pos[len(past_head_pos) - (5 * i) - 5][1]))
        screen.blit(clone_image, cRect)
        cur_rects.append(cRect)

    past_head_pos.append((head_rect.left, head_rect.top))
    if len(past_head_pos) > 150:
        past_head_pos.pop(0)

    screen.blit(food_surf, food_rect)
    screen.blit(head_image, head_rect)
    cur_rects.append(head_rect)

    if (head_rect.colliderect(food_rect)):
        while (checkCollide(food_rect, cur_rects)):
            food_rect.left = random.randint(0, 752)
            food_rect.top = random.randint(0, 752)
        clone_cnt += 1

    cur_rects.pop()
    start, game, score = False, True, clone_cnt
    if gameOver(up, down, right, left, head_rect, cur_rects):
        #print("game over | score: " + str(clone_cnt))
        cur_rects.clear()
        clone_cnt = 0
        head_image = pygame.image.load("snake/snake_head.png")
        head_image = pygame.transform.scale(head_image, (64, 64))
        head_image = pygame.transform.rotate(head_image, -90)
        head_rect.left, head_rect.top = 400, 400
        food_rect.left, food_rect.top = 600, 400
        up, down, left , right = False, False, False, True
        start, game = True, False
    
    return up, down, right, left, head_image, past_head_pos, food_rect, clone_cnt, start, game, score

def startScreen(start, game, score, clone_cnt):
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            pygame.quit()
            exit()
        if event.type == pygame.MOUSEBUTTONDOWN:
            if (play_rect.collidepoint(event.pos)):
                start, game = False, True
    screen.fill("white")
    screen.blit(play_surf, play_rect)
    screen.blit(text, text_rect)
    if score >= 0:
        #print("score" + str(score))
        score_surf = pygame.font.Font(None, 36).render("Score: " + str(score), True, "black")
        score_rect = score_surf.get_rect(centerx = play_rect.centerx, top = play_rect.bottom)
        screen.blit(score_surf, score_rect)
    return start, game

while True:
    if start:
        start, game = startScreen(start, game, score, clone_cnt)
    elif game:
        up, down, right, left, head_image, past_head_pos, food_rect, clone_cnt, start, game, score = gameScreen(
            up, down, right, left, head_image, past_head_pos, food_rect, clone_cnt, start, game, score
        )
        #print("score: " + str(score))
    
    pygame.display.update()
    clock.tick(30)
