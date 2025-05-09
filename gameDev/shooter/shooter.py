import pygame
import math
pygame.init()
screen = pygame.display.set_mode((800, 800))
pygame.display.set_caption("shooter")
clock = pygame.time.Clock()

#player = pygame.Surface((40, 40), pygame.SRCALPHA)
#pygame.draw.circle(player, "red", (20, 20), 20.0)
player_image = pygame.image.load("shooter/shooter.png")
#player_image = pygame.transform.rotate(player_image, 90)
player_copy = pygame.image.load("shooter/shooter.png")
player_copy = pygame.transform.rotate(player_copy, 90)
player_rect = player_image.get_rect(topleft = (400, 400))


#just stores angle that the bullet has to travel

bullet_image = pygame.image.load("shooter/bullet.png")
bullet_image = pygame.transform.rotate(bullet_image, -90)
bullet_mask = pygame.mask.from_surface(bullet_image)
bullet_rect = bullet_mask.get_bounding_rects()[0]
bullet_list = []

enemy_list = []
class Bullet:
    def __init__(self, x, y, angle, speed, image):
        self.x = x
        self.y = y
        self.angle = angle
        self.speed = speed
        self.image = pygame.transform.rotate(image, -math.degrees(angle))
        self.mask = pygame.mask.from_surface(self.image)
        self.rect = self.mask.get_bounding_rects()[0]
        self.rect.topleft = (x, y)
        print("raw x: " + str(x))
        print("ray y: " + str(y))
        print("self.rect.x: " + str(self.rect.x))
        print("self.rect.y: " + str(self.rect.y))
        print("degrees: " + str(math.degrees(angle)))
    def move(self):
        self.rect.x += self.speed * math.cos(self.angle)
        self.rect.y += self.speed * math.sin(self.angle)
    def display(self):
        screen.blit(self.image, self.rect)

class Enemy:
    def __init__(self, x, y, image):
        self.image = image
        self.mask = pygame.mask.from_surface(self.image)
        self.rect = self.mask.get_bounding_rects()[0]
        self.rect.center = (x, y)
        self.hp = 100
    def hit(self):
        self.hp-=20
        return self.hp
    def display(self):
        screen.blit(self.image, self.rect)
        
enemy_list.append(Enemy(x = 40, y = 100, image = pygame.image.load("shooter/enemy.png")))
while True:
    screen.fill("light blue")
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            pygame.quit()
            exit()
        if event.type == pygame.MOUSEBUTTONDOWN:
            #fire bullet gangy
            mx, my = pygame.mouse.get_pos()
            dx = mx - player_rect.centerx
            dy = my - player_rect.centery
            Tangle = math.atan2(dy, dx)
            print("Tangle: " + str(Tangle))
            bullet_list.append(Bullet(x = player_rect.x, y = player_rect.y, angle = Tangle, speed = 10, image = bullet_image))
    for b in bullet_list:
        b.move()
        b.display()
        if (len(enemy_list) > 0 and b.rect.colliderect(enemy_list[0].rect)):
            bullet_list.remove(b)
            print("HIT!")
            amt = enemy_list[0].hit()
            if amt == 0:
                print("done for")
                enemy_list.pop()
            continue
    keys = pygame.key.get_pressed()
    if keys[pygame.K_UP]:
        player_rect.y-=5
    if keys[pygame.K_DOWN]:
        player_rect.y+=5
    if keys[pygame.K_RIGHT]:
        player_rect.x+=5
    if keys[pygame.K_LEFT]:
        player_rect.x-=5
    mx, my = pygame.mouse.get_pos()
    dx = mx - player_rect.centerx
    dy = my - player_rect.centery
    angle = math.degrees(math.atan2(dy, dx))
    player_image = pygame.transform.rotate(player_copy, -angle)
    player_rect = player_image.get_rect(center = player_rect.center)
    screen.blit(player_image, player_rect)
    if (len(enemy_list) > 0):
        enemy_list[0].display()
    #screen.blit(bullet_image, (100, 100))
    pygame.display.update()
    clock.tick(30)