import socket
import pickle
import pygame
import sys

WIDTH, HEIGHT = 500, 500
WHITE = (255, 255, 255)
RED = (255, 0, 0)
BLUE = (0, 0, 255)
VEL = 5

# Connect to server
client = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
client.connect(("localhost", 5555))
local_ip, local_port = client.getsockname()
print(f"Client is using local port: {local_port}")
# Get player ID and starting position
player_id = pickle.loads(client.recv(1024))
player_pos = pickle.loads(client.recv(1024))

# Pygame setup
pygame.init()
win = pygame.display.set_mode((WIDTH, HEIGHT))
pygame.display.set_caption(f"Client - Player {player_id}")
clock = pygame.time.Clock()

def redraw_window(players):
    win.fill(WHITE)
    pygame.draw.rect(win, RED, (*players[0], 50, 50))
    pygame.draw.rect(win, BLUE, (*players[1], 50, 50))
    pygame.display.update()

running = True
while running:
    clock.tick(60)

    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            running = False

    keys = pygame.key.get_pressed()

    # Movement control for your player only
    if player_id == 0:  # WASD
        if keys[pygame.K_a]:
            player_pos = (player_pos[0] - VEL, player_pos[1])
        if keys[pygame.K_d]:
            player_pos = (player_pos[0] + VEL, player_pos[1])
        if keys[pygame.K_w]:
            player_pos = (player_pos[0], player_pos[1] - VEL)
        if keys[pygame.K_s]:
            player_pos = (player_pos[0], player_pos[1] + VEL)
    elif player_id == 1:  # Arrow keys
        if keys[pygame.K_LEFT]:
            player_pos = (player_pos[0] - VEL, player_pos[1])
        if keys[pygame.K_RIGHT]:
            player_pos = (player_pos[0] + VEL, player_pos[1])
        if keys[pygame.K_UP]:
            player_pos = (player_pos[0], player_pos[1] - VEL)
        if keys[pygame.K_DOWN]:
            player_pos = (player_pos[0], player_pos[1] + VEL)

    try:
        client.sendall(pickle.dumps(player_pos))
        players = pickle.loads(client.recv(1024))
        redraw_window(players)
    except:
        print("[CLIENT] Disconnected from server")
        running = False
client.close()
pygame.quit()
sys.exit()