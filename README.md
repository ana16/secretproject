# secretproject

Contributions

Our GitHub displays that there are only 2 contributors to the project. However, there were not only 2 people working on our TigerZone game. The reason GitHub shows this is because Matt, team leader and the creator of our GitHub project, was the only one able to successfully push files to the GitHub. Matt helped all the team members try to push their work to the GitHub, but only Nikita had some success. The remaining four team members were not able to successfully publish to GitHub. Rather than wasting time getting the GitHub to work perfectly for everyone, we simply each worked on individual files and all sent them to Matt. The pushed request and commit titles also include names of contributors.


# UML

![alt-tag](https://github.com/mattdmorris/secretproject/blob/master/uml/umlpng.png)

# Things to do

1) Write classes: boardState,tile,deck,entity,field,city,road,monastery,meeple,player

2) Design GUI (need to be able to efficiently export boardstate)

3) Move checking

4) Simple AI (probably just random moves to start with)


# Quick Git Guide

1) Install Github Desktop from here (this automatically downloads gitshell as well): https://desktop.github.com/

2) On the github page, press the fork button in the top right corner, this creates your own workspace for the project that you can work on and update.

3) Open Gitshell and navigate to the directory you want to work in: "cd {local directory}"

4) Download latest version of the project: "git clone https://github.com/{your-username}/secretproject.git",  if you created your own fork, {your-username} is your github name;

5) Add a remote repository. For our project the remote repository will be "https://github.com/mattdmorris/secretproject.git". This is the repository we will all update our versions to everytime theres a change. You can set this up with this command: "git remote add upstream https://github.com/mattdmorris/secretproject.git". Afterwards type this whenever you want to update to the latest version of the project: "git fetch upstream".

5) After making changes, you have to "git add .", then "git commit -m 'message'", then "git push"

6) To add to the project, make a pull request. Find the button on your fork of the project. This will compare code so everyone will see only the changes, then we can add it to the main project.




# Documentation

Summary:
We have three main objects that we will be interacting with: Board, Tile, Feature.

Each tile has 9 zones with features. In our code when we are referencing feature numbers on a tile, the order is: 

N,S,E,W,NE,NW,SE,SW,CENTER

Each tile is assigned features in the tile constructor. Each Feature has a list of tiles that is assigned to it.

This is how Tiles and Features are linked, Tile has a feature array, Features has a tileList.

The Board is a 2d array of tile pointers. Board and Tiles related in Board by pointers to tiles, and in tiles by x coords and y coords.

The critical function in Board is the addTile function. The addTile function trusts the caller about legal tile placement, 
it simply places the tile on the Board and attempts to combine each zone on it with adjacent zones in other tiles. The combination
process checks if adjacent features are the same type of Feature. The new tile "consumes" the old Feature with the use of 
repointFeatures function in Feature.

The AI is in the function random legal move. It takes a tile pointer as an input. It will run the function checkLegalMove. Check legal move is fairly self explanatory, it checks NSEW for matching feature name. It will check over the board's open location vector. 
This vector is updated on every addTile.

The game was tested with a GUI built in Javascript and HTML5. It uses the createjs engine and is in the graphics folder under Newfile.html  . You input the exportBoard.txt file that is produced by the board->exportBoardState function.

# Building the game

In secretproject folder, run "make all".











