import pygame
import random

pygame.init()
WIDTH, HEIGHT = 800, 600
screen = pygame.display.set_mode((WIDTH, HEIGHT))
pygame.display.set_caption("Pong")

WHITE = (255, 255, 255)
BLACK = (0, 0, 0)
BLUE = (0, 0, 255)
RED = (255, 0, 0)

paddle_width, paddle_height = 10, 100
ball_radius = 10

paddle1_x, paddle1_y = 20, HEIGHT // 2 - paddle_height // 2
paddle2_x, paddle2_y = WIDTH - 30, HEIGHT // 2 - paddle_height // 2

ball_x, ball_y = WIDTH // 2, HEIGHT // 2
ball_dx, ball_dy = 5, 5

running = True
clock = pygame.time.Clock()

while running:
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            running = False

    # Player 1 movement
    keys = pygame.key.get_pressed()
    if keys[pygame.K_w]:
        paddle1_y -= 5
    if keys[pygame.K_s]:
        paddle1_y += 5

    # Player 2 movement (controlled by AI or other logic)
    # ...

    # Ball movement
    ball_x += ball_dx
    ball_y += ball_dy

    # Ball collision with walls
    if ball_y <= 0 or ball_y >= HEIGHT - ball_radius:
        ball_dy = -ball_dy
    if ball_x <= 0 or ball_x >= WIDTH - ball_radius:
        ball_dx = -ball_dx

    # Ball collision with paddles
    if (ball_x - ball_radius <= paddle1_x + paddle_width and
            ball_y >= paddle1_y and ball_y <= paddle1_y + paddle_height):
        ball_dx = -ball_dx
    if (ball_x + ball_radius >= paddle2_x and
            ball_y >= paddle2_y and ball_y <= paddle2_y + paddle_height):
        ball_dx = -ball_dx

    # Update screen
    screen.fill(BLACK)
    pygame.draw.rect(screen, WHITE, (paddle1_x, paddle1_y, paddle_width, paddle_height))
    pygame.draw.rect(screen, WHITE, (paddle2_x, paddle2_y, paddle_width, paddle_height))
    pygame.draw.circle(screen, WHITE, (ball_x, ball_y), ball_radius)
    pygame.display.flip()

    clock.tick(60)

pygame.quit()
