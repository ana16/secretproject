# secretproject
# UML

![alt-tag](https://github.com/mattdmorris/secretproject/blob/master/umlpng.png)

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
