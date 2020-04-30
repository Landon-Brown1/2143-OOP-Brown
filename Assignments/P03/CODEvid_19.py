# Import and initialize the pygame library
import pygame
import random
import math
import sys

# list of colors
colors = ["red", "white", "grey", "blue", "pink"]
states = ["susceptible", "infected", "recovered"]

im_path = "C:/Users/Landon Brown/Desktop/Git Repositories/2143-OOP-Brown/Assignments/P03/images/"

config = {
    "sprite": {
        "width": 15,
        "height": 15,
        "speed": 1,
    },
    "images": {
        "blue": im_path + "circle_blue_30x30.png",
        "light_blue": im_path + "pac_light_blue_30x30.png",
        "red": im_path + "circle_red_30x30.png",
        "white": im_path + "circle_white_30x30.png",
        "yellow": im_path + "pac_yellow_30x30.png",
        "orange": im_path + "pac_orange_30x30.png",
        "green": im_path + "pac_green_30x30.png",
        "black": im_path + "pac_black_30x30.png",
        "grey": im_path + "circle_grey_30x30.png",
        "pink": im_path + "circle_pink_30x30.png"
    },
    "game": {
        "width": 750,
        "height": 750,
        "day": 0,
        "fps": 40,
        "loop_count": 0
    },
    "sim": {
        "social_distancing": False,
        "social_distance": 20,
        "infection_radius": 10,
        "infection_rate": .20,
        "population_count": 50,
        "pid": 1,
    }
}


class Person(pygame.sprite.Sprite):
    """
    This class represents the ball.
    It derives from the "Sprite" class in Pygame
    """
    def __init__(self, **kwargs):
        """ Constructor. 
        """

        # Call the parent class (Sprite) constructor
        super().__init__()
        self.width = kwargs.get("width", 10)
        self.height = kwargs.get("height", 10)
        self.speed = kwargs.get("speed", 1)
        self.coord = kwargs.get("coord", None)
        self.color = kwargs.get("color", "green")
        self.state = kwargs.get("susceptible")

        # print(self.coord)

        # choose sprite direction
        self.dx = 0
        self.dy = 0
        while self.dx + self.dy == 0:
            self.dx = random.choice([1, -1, 0])
            self.dy = random.choice([1, -1, 0])

        # give our sprite an image and resize it
        self.image = pygame.image.load(config["images"][self.color])
        self.image = pygame.transform.scale(self.image,
                                            (self.width, self.height))

        # set sprite position
        if self.coord == None:
            self.x = int(random.random() * config["game"]["width"])
            self.y = int(random.random() * config["game"]["height"])
        else:
            self.x = self.coord[0]
            self.y = self.coord[1]

        # sprite bounding rectangle
        self.rect = self.image.get_rect(center=(self.x, self.y))

    def setDxDy(self, dx, dy):
        self.dx = dx
        self.dy = dy

    def getDxDy(self):
        return (self.dx, self.dy)

    def changeDirection(self, sides_contacted):
        if sides_contacted["top"]:
            self.dy = 1
        if sides_contacted["bottom"]:
            self.dy = -1
        if sides_contacted["left"]:
            self.dx = 1
        if sides_contacted["right"]:
            self.dx = -1

    def move(self):

        sides_contacted = self.checkWalls()

        self.changeDirection(sides_contacted)

        if self.dx < 0:
            self.rect.x -= self.speed
        elif self.dx > 0:
            self.rect.x += self.speed

        if self.dy < 0:
            self.rect.y -= self.speed
        elif self.dy > 0:
            self.rect.y += self.speed

    def checkCollide(self, other):
        sides_contacted = {
            "top": False,
            "bottom": False,
            "left": False,
            "right": False
        }

        if self.rect.colliderect(other.rect):

            if self.rect.top < other.rect.top:
                sides_contacted["bottom"] = True
                self.rect.y -= abs(self.rect.y - other.rect.y) // 2
            if self.rect.left < other.rect.left:
                sides_contacted["right"] = True
                self.rect.x -= abs(self.rect.x - other.rect.x) // 2
            if self.rect.right > other.rect.right:
                sides_contacted["left"] = True
                self.rect.x += abs(self.rect.x - other.rect.x) // 2
            if self.rect.bottom > other.rect.bottom:
                sides_contacted["top"] = True
                self.rect.y += abs(self.rect.y - other.rect.y) // 2

            # self.rect.x += (self.rect.x-other.rect.x)
            # self.rect.y += (self.rect.y-other.rect.y)

            self.changeDirection(sides_contacted)

            return True

        return False

    def checkWalls(self):
        sides = {"top": False, "bottom": False, "left": False, "right": False}

        if self.rect.top <= 0:
            sides["top"] = True
        if self.rect.left <= 0:
            sides["left"] = True
        if self.rect.right >= config["game"]["width"]:
            sides["right"] = True
        if self.rect.bottom >= config["game"]["height"]:
            sides["bottom"] = True

        return sides

class SimStats(object):
    def __init__(self):
        pass

class Community(SimStats):
    def __init__(self):
        pass

class Simulation:
    def __init__(self, **kwargs):
        self.population = []
        self.infected = []
        self.game_width = kwargs.get("width", 500)
        self.game_height = kwargs.get("height", 500)
        self.population_count = kwargs.get("population_count", 10)
        self.sprite_group = pygame.sprite.Group()
        self.screen = kwargs.get("screen", None)

        print(self.screen)

        if self.screen == None:
            print(
                "Error: Simulation needs an instance of a pygame surface / screen!"
            )
            sys.exit()

    def populateSim(self, pos=None):
        for _ in range(self.population_count):
            self.addPerson()

    def addPerson(self, **kwargs):
        width = kwargs.get("width", config["sprite"]["width"])
        height = kwargs.get("height", config["sprite"]["height"])
        speed = kwargs.get("speed", config["sprite"]["speed"])
        state = kwargs.get("state", random.choice(states))
        if state == "infected":
            color = kwargs.get("color", "red")
        elif state == "susceptible":
            color = kwargs.get("color", "white")
        elif state == "recovered":
            color = kwargs.get("color", "blue")
        else: color = kwargs.get("color", random.choice(colors))
            
        x = random.randint(0, self.game_width)
        y = random.randint(0, self.game_height)
        coord = kwargs.get("coord", [x, y])

        p = Person(color=color,
                   width=config["sprite"]["width"],
                   height=config["sprite"]["height"],
                   speed=config["sprite"]["speed"],
                   coord=coord)
                #    state=state?
        self.population.append(p)
            
        self.sprite_group.add(p)

    def simRun(self):
        # loop through each person and call a move method
        for i in range(len(self.population)):
            self.population[i].move()
            for j in range(len(self.population)):
                if self.population[i] != self.population[j]:
                    collided = self.population[i].checkCollide(
                        self.population[j])
                    if collided:
                        dx, dy = self.population[i].getDxDy()
                        self.population[j].setDxDy(dx * -1, dy * -1)

        self.sprite_group.draw(self.screen)


#__________________________________________________________________________

if __name__ == '__main__':
    pygame.init()




    # define the RGB value for white, 
    #  green, blue colour . 
    white = (255, 255, 255) 
    green = (0, 255, 0) 
    blue = (0, 0, 128)
    grey = (25, 25, 25) 
    
    # assigning values to X and Y variable 
    X = config["game"]["width"] - 20
    Y = config["game"]["height"] - 20
    
    # create the display surface object 
    # of specific dimension..e(X, Y). 
    display_surface = pygame.display.set_mode((X, Y )) 
    
    # set the pygame window name 
    pygame.display.set_caption('Show Text') 
    
    # create a font object. 
    # 1st parameter is the font file 
    # which is present in pygame. 
    # 2nd parameter is size of the font 
    font = pygame.font.Font('freesansbold.ttf', 20) 




    # Set up the drawing window
    screen = pygame.display.set_mode(
        [config["game"]["width"], config["game"]["height"]])

    sim = Simulation(screen=screen,
                     width=config["game"]["width"],
                     height=config["game"]["height"],
                     population_count=config["sim"]["population_count"])

    sim.populateSim()

    # helps keep game loop running at
    # specific frames per second
    clock = pygame.time.Clock()

    # Run until the user asks to quit
    running = True

    for person in sim.population:
            print(person.state)


    #___ GAME LOOP ____________________________________________________________
    while running:
        # Fill the background with blackish
        # Do not do this after you draw sprites!
        screen.fill((30, 30, 30))
        
        # create a text suface object, 
        # on which text is drawn on it. 

        
        text = font.render('There are ' + str(len(sim.population)) + " Susceptible, " + str(len(sim.population)) + ' Infected, ' + str(len(sim.population)) + ' Recovered, and ' + str(len(sim.population)) + ' Total', True, white, grey) 
        
        # create a rectangular object for the 
        # text surface object 
        textRect = text.get_rect()  
        
        # set the center of the rectangular object. 
        textRect.right = config["game"]["width"]
        textRect.bottom = config["game"]["height"]

        # copying the text surface object 
        # to the display surface object  
        # at the center coordinate. 
        display_surface.blit(text, textRect)

        # Did the user click the window close button?
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                running = False

            # handle MOUSEBUTTONUP
            if event.type == pygame.MOUSEBUTTONUP:
                if event.button == 1:               # LeftMB
                    pos = pygame.mouse.get_pos()    

                    sim.addPerson(coord=pos,state="susceptible")
                elif event.button == 3:             # RightMB
                    pos = pygame.mouse.get_pos()

                    sim.addPerson(coord=pos,state="infected")
                elif event.button == 2:             # MiddleMB
                    pos = pygame.mouse.get_pos()

                    sim.addPerson(coord=pos,state="recovered")

        #___CONTROL SIMULATION HERE_____________________________________________________________

        sim.simRun()

        #___END CONTROL SIMULATION_____________________________________________________________

        # This keeps game loop running at a constant FPS
        clock.tick(config["game"]["fps"])  # FPS = frames per second

        # Count number of loops game runs (careful, this number could get LARGE)
        config["game"]["loop_count"] += 1

        # Flip the display (refresh the screen)
        pygame.display.flip()

#___ END GAME LOOP ____________________________________________________________
# Done! Time to quit.
    pygame.quit()
