######################################################
# Project: <Project 2 game>
# UIN: <661888752>
# repl.it URL: <https://replit.com/@CS111-Fall2021/Project-2-JoseBolan#main.py>

######################################################
## imports
import turtle
import random





#dictinoaries for game objects
harm_objs = [{'t': turtle.Turtle(), 'x': 0, 'y': 0, 'radius': 20, 'image': "ezgif.com-gif-maker.gif", "type": 'harm1L','speed': .2 },{'t': turtle.Turtle(), 'x': 0, 'y': 0, 'radius': 20, 'image': "ezgif.com-gif-maker.gif", 'type': 'harm1R', 'speed': .1}, {'t': turtle.Turtle(), 'x': 0, 'y': 0, 'radius': 20, 'image': "ezgif.com-gif-maker.gif", 'type': 'harm2L', 'speed': .2}, {'t': turtle.Turtle(), 'x': 0, 'y': 0, 'radius': 20, 'image': "ezgif.com-gif-maker.gif", 'type': 'harm2R', 'speed': .1 } ] 

#dictionary for player
player = {'t': turtle.Turtle(), 'x': 0, 'y': -125, 'radius': 20, 'image': "40 by 40 dragonB.gif"}
good = {'t': turtle.Turtle(), 'x': 0, 'y': 125, 'radius': 20, 'image': "safe 40 by 40.gif"}

#holds extra stuff like turtles for writting text, lives and scores
extra = {'t': turtle.Turtle(),'t2': turtle.Turtle(), 't3': turtle.Turtle(),'lives': 3, 'score': 0, 'level': 0}

#screen setup stuff
s = turtle.Screen()
s.screensize(300,300)
w, h = s.screensize()
s.setup(w + 20, h + 20)

#collision setup
playerloc = player['x'], player['y']
pradius = player ['radius']

objloc = harm_objs[0]['x'], harm_objs[0]['y']
objradius = harm_objs[0]['radius']

objloc2 = harm_objs[1]['x'], harm_objs[1]['y']
objradius2 = harm_objs[1]['radius']

objloc3 = harm_objs[2]['x'], harm_objs[2]['y']
objradius3 = harm_objs[2]['radius']

objloc4 = harm_objs[3]['x'], harm_objs[3]['y']
objradius4 = harm_objs[3]['radius']

goodloc = good['x'], good['y']
goodradius = good['radius']

#collision function and calls
def collision5 (playerLoc, pradius, goodloc, goodradius):
  distance = player['t'].distance(good['t'])
  radius = pradius + goodradius
  if distance < radius:
    return True
  return False

collision5 (playerloc, pradius, goodloc, goodradius)

def collison4 (playerloc, pradius, objloc4, objradius4):
  distance = player['t'].distance(harm_objs[3]['t'])
  radius = pradius + objradius
  if distance < radius:
    return True
  return False

collison4 (playerloc, pradius, objloc4, objradius4)

def collison3 (playerloc, pradius, objloc3, objradius3):
  distance = player['t'].distance(harm_objs[2]['t'])
  radius = pradius + objradius
  if distance < radius:
    return True
  return False

collison3 (playerloc, pradius, objloc3, objradius3)

def collison2 (playerloc, pradius, objloc2, objradius2):
  distance = player['t'].distance(harm_objs[1]['t'])
  radius = pradius + objradius
  if distance < radius:
    return True
  return False

collison2(playerloc, pradius, objloc2, objradius2)

def collison (playerloc, pradius, objloc, objradius):
  distance = player['t'].distance(harm_objs[0]['t'])
  radius = pradius + objradius
  if distance < radius:
    return True
  return False

collison(playerloc, pradius, objloc, objradius)

#player movement
def playermove ():
  
  #player character setup
  t = player['t']
  icon = player['image']
  t.hideturtle()
  t.penup()
  t.goto(player['x'],player['y'])
  t.pendown()
  t.showturtle()
  s.addshape(icon)
  t.shape(icon)
  
  #move up
  def up():
    t.setheading(90)
    t.penup()
    t.forward(50)
    t.pendown()
  
  #move down
  def down():
    t.setheading(270)
    t.penup()
    t.forward(50)
    t.pendown()
  
  #move left
  def left():
    t.setheading(180)
    t.penup()
    t.forward(50)
    t.pendown()
 
  #move right
  def right():
    t.setheading(0)
    t.penup()
    t.forward(50)
    t.pendown()
  
  #setting keys up
  s.onkey(up, 'w')
  s.onkey(down, 's')
  s.onkey(left,'a')
  s.onkey(right, 'd')
  #listening for keys
  s.listen()

#main fucntion for game
def main():

  #sets backgrounds
  bgp = "BCG Resized.gif"
  bgp2 = "AcCNd.gif"
  s.bgpic(bgp)


  #player movemnet function called
  playermove()

  #takes care of safe area properties
  t1 = good['t']
  icon = good['image']
  s.addshape(icon)
  t1.hideturtle()
  t1.shape(icon)
  t1.penup()
  t1.goto(good['x'], good['y'])
  t1.pendown()
  t1.showturtle()

  #begins animation of harm objects
  s.tracer(0)
  for obj in harm_objs:
    img = obj["image"]  
    t = obj["t"] 
    s.addshape(img)
    t.shape(img)
    

  while (extra['lives'] != 0):
    #stops it from smeering
    for obj in harm_objs:
       obj["t"].clear()
    
    #this collision is for good object
    if collision5 (playerloc, pradius, goodloc, goodradius) == True:
      player ['x'] = 0
      player ['y'] = -125
      player['t'].penup()
      
      for obj in harm_objs:
        obj['speed'] += .1
      extra['score'] += 1
      extra['level'] += 1
      score = extra['score']
      #print('current score ' + str(score))
      player['t'].goto(player['x'], player['y'])
      player['t'].pendown()
    
    #rest collison conditional statements are for harm objects
    if collison4 (playerloc, pradius, objloc4, objradius4) == True:
      player ['x'] = 0
      player ['y'] = -125
      player['t'].penup()
      extra['lives'] -= 1
      lives = extra['lives']
      #print('lives left ' + str(lives))
      player['t'].goto(player['x'], player['y'])
      player['t'].pendown()

    if collison3 (playerloc, pradius, objloc3, objradius3) == True:
      player ['x'] = 0
      player ['y'] = -125
      player['t'].penup()
      extra['lives'] -= 1
      lives = extra['lives']
      #print('lives left ' + str(lives))
      player['t'].goto(player['x'], player['y'])
      player['t'].pendown()
    
    if collison2 (playerloc, pradius, objloc2, objradius2) == True:
      player ['x'] = 0
      player ['y'] = -125
      player['t'].penup()
      extra['lives'] -= 1
      lives = extra['lives']
      #print('lives left ' + str(lives))
      player['t'].goto(player['x'], player['y'])
      player['t'].pendown()

    if collison(playerloc, pradius, objloc, objradius) == True:
      player ['x'] = 0
      player ['y'] = -125
      player['t'].penup()
      extra['lives'] -= 1
      lives = extra['lives']
      #print('lives left ' + str(lives))
      player['t'].goto(player['x'], player['y'])
      player['t'].pendown()
    

    #score handeler
    extra['t'].clear()
    extra['t'].hideturtle()
    extra['t'].penup()
    extra['t'].goto(-100,120)
    extra['t'].pendown()
    extra['t'].write("Game Score " + str(extra['score']), font=("Arial", 10, 'normal'), align= "center")

    #live handeler
    extra['t2'].clear()
    extra['t2'].penup()
    extra['t2'].hideturtle()
    extra['t2'].goto(100,120)
    extra['t2'].pendown()
    extra['t2'].write("Lives Left  " + str(extra['lives']), font=("Arial", 10, 'normal'), align= "center")

    #level handeler
    extra['t3'].clear()
    extra['t3'].penup()
    extra['t3'].hideturtle()
    extra['t3'].goto(100,-140)
    extra['t3'].pendown()
    extra['t3'].write("Level:  " + str(extra['level']), font=("Arial", 10, 'normal'), align= "center")


    
    #going right bottom 
    for obj in harm_objs:
      if (obj["type"] == "harm1L"):
        obj["x"] += obj["speed"]
        obj["y"] = -75
        if (obj["x"] > w/2):
          obj["x"] = -w/2
    
    #going left bottom 
    for obj in harm_objs:
      if (obj["type"] == "harm1R"):
        obj["x"] -= obj["speed"]
        obj["y"] = -25
        if (obj["x"] < (-w/2)):
             obj["x"] = +w/2


      #going right top
    for obj in harm_objs:
      if (obj["type"] == "harm2L"):
        obj["x"] += obj["speed"]
        obj["y"] = 25
        if (obj["x"] > w/2):
          obj["x"] = -w/2
 
 
    #going left top
    for obj in harm_objs:
      if (obj["type"] == "harm2R"):
        obj["x"] -= obj["speed"]
        obj["y"] = 75
        if (obj["x"] < (-w/2)):
            obj["x"] = +w/2
    
   
    for obj in harm_objs:  
      t = obj["t"]
      x = obj["x"]
      y = obj["y"]
      t.goto(x, y)    
      s.update()
  else:
    
    #Calls end screen for when lives = 0 and loop is killed
    def endscreen():
      wn=turtle.Screen()
      extra['t'].clear()
      extra['t2'].clear()
      extra['t3'].clear()
      t = extra['t']
      t.hideturtle()
      wn.bgcolor("red")
      t.penup()
      t.goto(0,0)
      t.pendown()
      t.write("Game Over", font=("Arial", 20, 'normal', 'bold'), align= "center")
      t.penup()
      t.goto(0,-70)
      t.pendown()
      t.write("Final Score: " + str(extra['score']) , font=("Arial", 10, 'normal'), align= "center")
      for obj in harm_objs:
       obj["t"].reset()
      good['t'].reset() 
      player['t'].reset()
      s.bgpic(bgp2)
    
    #calls end screen
    endscreen()


#start screen stuff
def start_screen():
  wn=turtle.Screen()
  extra['t'].hideturtle()
  t = extra['t']
  wn.bgcolor("grey")
  t.write("Ball Bash Z", font=("Arial", 20, 'normal', 'bold'), align= "center")
  t.penup()
  t.goto(0,-70)
  t.write("Press Enter to play", font=("Arial", 10, 'normal'), align= "center")
  t.penup()
  t.goto(0,-100)
  t.write("Use the W. A, S, D keys to move", font=("Arial", 10, 'normal'), align= "center")

start_screen()

#keypress needed for game to start 
def enter():
  t = extra['t']
  t.hideturtle()
  t.clear()
  #activates main function
  main()


s.onkey(enter, 'Return')
s.listen()