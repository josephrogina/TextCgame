#include "header.h"

char *help="help";
char key = 'n';
char item = 'n';
char bar = 'n';
char leiut = 'n';
char grand = 'n';

int main(void)
{
    char choice;

    clrscr();//system("clear");
    printf("\n\n\n\n");
    printf("Welcome to my first game design!\n");
    printf("Any requests or questions, contact Rogina Systems\n");
    printf("at joseph@rogina.net\n");
    printf("In this game, you are trapped in a building.\n");
    printf("You need to find a way out. Many options\n");
    printf("are at your disposal.\n\n");
    printf("Use key phrases or words like turn left, or try window..\n");
    printf("Each section hints at your options...\n");
    printf("Else use words like search & leave when no hint is given.\n");
    printf("If you REALLY need it, type help for options.\n");
    printf("\nSorry, no graphics in this game.\n");
    printf("Press enter to continue...\n");
    fflush(stdin);
    scanf("%c",&choice);
    fflush(stdin);

    door();

return 0;
}

void door(void)
{
    char choice='n';
    int error;
    char choices[ SIZE ];
    char *right="right";
    char *left="left";
    char *picture="picture";
    char *door="door";

    clrscr();//system("clear");
    printf("You are standing in the middle of a room,\n");
    printf("in front of you is the locked door to the outside.\n");
    printf("On the left of the door is a picture.\n");

    do
    {
    printf("\nWhat do you do?\n");
    fflush(stdin);
    gets(choices);
    fflush(stdin);

    if((strstr(choices,help)) != 0)
    {
      printf("Enter: right, left, door, or picture.\n");
      error = 1;
    }//help.
    if((strstr(choices,right)) != 0)
    {
       error = 0;
       dresser();
    }//if right.
    else
    if((strstr(choices,left)) != 0)
    {
       error = 0;
       mirror();
    }//if left.
    else
    if((strstr(choices,picture)) != 0)
    {
       printf("The picture is of a small sail boat,\n");
       printf("there is nothing behind it.\n");
       error = 1;
    }//if picture.
    else
    if((strstr(choices,door)) != 0)
    {
       if(key == 'y')
       {
    printf("The door is locked.\n");
	  printf("But you can pick the lock with the wire!");
	  sleep(2);
	  hall();
       }//if.
       else
       {
	  printf("I said the door is locked. Idiot!!!\n");
	  error = 1;
       }//else.
    }//if door.
    else
    if((strstr(choices,right)) == 0 || (strstr(choices,left)) == 0 ||
       (strstr(choices,picture)) == 0 || (strstr(choices,door)) == 0 ||
       (strstr(choices,help)) == 0)
    {
	printf("You're not too bright.");
	error = 1;
    }//if else.
    }while(error == 1);
}//door.

void mirror(void)
{
    int error = 1;
    char choice='n';
    char choices[ SIZE ];
    char *right="right";
    char *left="left";
    char *mirror="mirror";

    clrscr();//system("clear");
    printf("\n\n\n");
    printf("You're staring at yourself in a full size mirror.\n");

    do
    {
    printf("What do you do?\n");
    fflush(stdin);
    gets(choices);
    fflush(stdin);

    if((strstr(choices,help)) != 0)
    {
      printf("Enter: right, left, or mirror.\n");
      error = 1;
    }//help.
    if((strstr(choices,right)) != 0)
    {
       error = 0;
       door();
    }//if right.
    else
    if((strstr(choices,left)) != 0)
    {
       error = 0;
       window();
    }//if left.
    else
    if((strstr(choices,mirror)) != 0)
    {
       if(item == 'y')
       {
	  printf("You throw the statue at the mirror...\n");
	  printf("and it breaks...\n");
	  printf("but you awake the sleeping guard ");
	  printf("and he shoots you!");
	  printf("Sorry, maybe I'll come to your services.\n");
	  exit(0);
       }//if.
       else
       {
	  error = 1;
	  clrscr();//system("clear");
	  printf("The mirror is 5 feet high, and 6 feet long.\n");
	  printf("It sets about 3 feet off the ground.\n");
	  printf("It seems to be sealed all the way around.\n");
       }//else.
    }//if mirrror.
    else
    if((strstr(choices,right)) == 0 || (strstr(choices,left)) == 0 ||
       (strstr(choices,mirror)) == 0 || (strstr(choices,help)) == 0)
    {
	error = 1;
	printf("don't be an idiot!\n");
    }//if else.
    }while(error == 1);
}//mirror.

void dresser(void)
{
    int error = 1;
    char choice='n',bible='n';
    char choices[ SIZE ];
    char *right="right";
    char *left="left";
    char *drawers="drawers";
    char *statue="statue";

    clrscr();//system("clear");
    printf("\n\n\n");
    printf("In front of you is a dresser.\n");
    printf("It has three drawers.\n");
    if(item != 'y' && item != 'g')
       printf("On top is a statue.\n");

    do
    {
    printf("What do you do?\n");
    fflush(stdin);
    gets(choices);
    fflush(stdin);

    if((strstr(choices,help)) != 0)
    {
      printf("Enter: right, left, drawers, or statue.\n");
      error = 1;
    }//help.
    if((strstr(choices,right)) != 0)
    {
       error = 0;
       window();
    }//if right.
    else
    if((strstr(choices,left)) != 0)
    {
       error = 0;
       door();
    }//if left.
    else
    if((strstr(choices,drawers)) != 0)
    {
       error = 1;
       printf("The top drawer contains a Bible,\n");
       printf("the others are empty.\n");
       printf("Do you wish to pray?(y/n): ");
       fflush(stdin);
       scanf("%c",&bible);
       if(bible == 'y')
       {
	  printf("You really think it will help?\n");
       }//if.
    }//if drawers.
    else
    if((strstr(choices,statue)) != 0)
    {
       error = 1;
       if(item == 'y' || item == 'g')
	  printf("You already grabed the statue.\n");

       else
       {
	  printf("You pick up the statue and realize its heavy.\n");
	  printf("You decide to hang on to it.\n");
	  item = 'y';
       }//else.
    }//if statue.
    else
    if((strstr(choices,right)) == 0 || (strstr(choices,left)) == 0 ||
       (strstr(choices,drawers)) == 0 || (strstr(choices,statue)) == 0 ||
       (strstr(choices,help)) == 0)
    {
	error = 1;
	printf("stupid! stupid! stupid!\n");
    }//if else.
    }while(error == 1);
}//dresser.

void window(void)
{
    int error = 1;
    char choice='n';
    char choices[ SIZE ];
    char *right="right";
    char *left="left";
    char *window="window";
    char *bench="bench";

    printf("In front of you is a window.\n");
    printf("There are no bars on the window.\n");
    if(key != 'y' && key != 'k')
      printf("In front of the window is a bench.\n");

    do
    {
	printf("What do you do?");
	fflush(stdin);
	gets(choices);
	fflush(stdin);

	if((strstr(choices,help)) != 0)
	{
	   printf("Enter: right, left, window, or bench.\n");
	   error = 1;
	}//help.
	if((strstr(choices,right)) != 0)
	{
	   error = 0;
	   mirror();
	}//if right.
	else
	if((strstr(choices,left)) != 0)
	{
	   error = 0;
	   dresser();
	}//if left.
	else
	if((strstr(choices,window)) != 0)
	{
	   if(item == 'y')
	   {
	     error = 0;
	     printf("You throw the statue through the window,\n");
	     printf("and climb out the window...\n");
	     sleep(3);
	     printf("and right into the dog pen!\n");
	     printf("At least I don't have to feed the dogs.\n");
	     exit(0);
	   }//if.
	   else
	   {
	     error = 1;
	     printf("The window seems fairly thin,\n");
	     printf("but extremely dirty. you cant see anything.\n");
	   }//else.
	}//if window.
	else
	if((strstr(choices,bench)) != 0)
	{
	   error = 1;
	   if(key == 'y' || key == 'k')
	      printf("You already totaled it.");
	   else
	   {
	     printf("The bench is small and feeble, ");
	     printf("and falls apart when you touch it.\n");
	     printf("Your notice some wire poking out, ");
	     printf("and decide to keep it.\n");
	     key = 'y';
	   }//else.
	}//if bench.
	else
	if((strstr(choices,right)) == 0 || (strstr(choices,left)) == 0 ||
	   (strstr(choices,window)) == 0 || (strstr(choices,bench)) == 0 ||
	   (strstr(choices,help)) == 0)
	{
	   error = 1;
	   printf("NO!\n");
	}//if else.
    }while(error == 1);
}//window.

void hall(void)
{
    char choice='n';
    int error = 1;
    char choices[ SIZE ];
    char *right="right";
    char *left="left";
    char *back="back";

    clrscr();//system("clear");
    printf("\n\nYour standing in a hall stretching right & left.\n");
    printf("Behind you is the open door you just came from.\n");

    do
    {
       printf("What do you do?\n");
       fflush(stdin);
       gets(choices);
       fflush(stdin);

       if((strstr(choices,help)) != 0)
       {
	 printf("Enter: right, left, or back.\n");
	 error = 1;
       }//help.
       if((strstr(choices,right)) != 0)
       {
	  error = 0;
	  righthall();
       }//if right.
       else
       if((strstr(choices,left)) != 0)
       {
	  error = 0;
	  lefthall();
       }//if left.
       else
       if((strstr(choices,back)) != 0)
       {
	  error = 0;
	  door();
       }//if back.
       else
       if((strstr(choices,left)) == 0 || (strstr(choices,right)) == 0 ||
	  (strstr(choices,back)) == 0 || (strstr(choices,help)) == 0)
       {
	   error = 1;
	   printf("Your hopeless...\n");
	   sleep(3);
       }//if else
    }while(error == 1);

}//hall.

void righthall(void)
{
    char choice='n';
    int error=1;
    char choices[ SIZE ];
    char *left="left";
    char *back="back";

    clrscr();//system("clear");
    printf("\n\nYou're at the right end of the hallway.\n");
    printf("There is another hall stretching off to your left.\n");
    do
    {
       printf("What do you do?");
       fflush(stdin);
       gets(choices);
       fflush(stdin);

       if((strstr(choices,help)) != 0)
       {
	 printf("Enter: left or back.\n");
	 error = 1;
       }//help.
       if((strstr(choices,left)) != 0)
       {
	  error = 0;
	  hallway();
       }//if left.
       else
       if((strstr(choices,back)) != 0)
       {
	  error = 0;
	  hall();
       }//if back.
       else
       if((strstr(choices,left)) == 0 || (strstr(choices,back)) == 0 ||
	  (strstr(choices,help)) == 0)
       {
	  error = 1;
	  printf("Wrong choice you dork.");
       }//if else.
    }while(error = 1);
}//righthall.

void lefthall(void)
{
   int error = 1;
   char choice='n';
   char choices[ SIZE ];
   char *left="left";
   char *opposit="opposite";
   char *back="back";

   clrscr();//system("clear");
   printf("\n\nYou run to the left of the hallway\nand discover two doors,");
   printf("\one on your left and one\non the opposite side of the hall.\n");
   do
   {
     printf("What do you do?\n");
     fflush(stdin);
     gets(choices);
     fflush(stdin);

     if((strstr(choices,help)) != 0)
     {
	printf("Enter: left, opposite, or back.\n");
	error = 1;
     }//help.
     if((strstr(choices,left)) != 0)
     {
	error = 0;
	guard();
     }//if left.
     else
     if((strstr(choices,opposit)) != 0)
     {
       error = 0;
       coffeeroom();
     }//if opposit.
     else
     if((strstr(choices,back)) != 0)
     {
       error = 0;
       hall();
     }//if back.
     else
     if((strstr(choices,left)) == 0 || (strstr(choices,opposit)) == 0 ||
	(strstr(choices,back)) == 0 || (strstr(choices,help)) == 0)
     {
       error = 1;
       printf("*#%%&!^#$@!\n");
     }//if else.
   }while(error == 1);
}//lefthall.

void guard(void)
{
    int error=1;
    char choice='n';
    char choices[ SIZE ];
    char *attack="kill";
    char *leave="leave";
    char *ask="ask";

    clrscr();//system("clear");
    if(item == 'g')
      printf("The guard lays slumped over the table where you left him.\n");
    else
      printf("A guard is sleeping in front of a window.\n");

      printf("Through the window is the room you started in.\n");
    do
    {
       printf("What do you do?\n");
       fflush(stdin);
       gets(choices);
       fflush(stdin);

       if((strstr(choices,help)) != 0)
       {
	 printf("Enter: kill, leave, or ask.\n");
	 error = 1;
       }//help.
       if((strstr(choices,attack)) != 0)
       {
	  error = 1;
	  if(item == 'g')
	     printf("The guard isn't going to get any deader.\n");
	  else
	  if(item == 'y')
	  {
	     printf("You crush the guards skull with the statue,\n");
	     printf("and trade off the statue for his .45!\n");
	     sleep(2);
	     printf("SSSMMMMMOOOOKIN!!\n");
	     item = 'g';
	  }//if.
	  else
	  {
	     printf("You jump on top of the guard, but do little ");
	     printf("more than wake him.\nYou're left lying on the");
	     printf(" ground with a 3in. diameter hole in your head");
	     printf(",\nand smoke rising from the barrel of his .45");
	     printf(".\nMaybe you'll fare better in the next life.\n");
	     exit(0);
	  }//else.
       }//if attack.
       else
       if((strstr(choices,leave)) != 0)
       {
	 error = 0;
	 lefthall();
       }//if leave.
       else
       if((strstr(choices,ask)) != 0)
       {
	  error = 0;
	  if(item == 'g')
	  {
	     printf("Who are you going to ask?\n");
	     printf("You destroyed the guard.\n");
	  }//if.
	  else
	  {
	     printf("It's your funeral.\n");
	     printf("You walk in politely, but do little ");
	     printf("more than wake him.\nYou're left lying on the");
	     printf(" ground with a 3in. diameter hole in your head");
	     printf(",\nand smoke rising from the barrel of his .45");
	     printf(".\nMaybe you'll fare better in the next life.\n");
	     exit(0);
	  }//else.
       }//if ask.
       else
       if((strstr(choices,attack)) == 0 || (strstr(choice,leave)) == 0 ||
	  (strstr(choices,ask)) == 0 || (strstr(choices,help)) == 0)
       {
	    error = 1;
	    printf("You have a really low IQ, don't you.\n");
       }//if else.
    }while(error == 1);
}//guard.

void coffeeroom(void)
{
   int error = 1;
   char choice='n';
   char choices[SIZE];
   char *search="search";
   char *leave="leave";

   clrscr();//system("clear");
   printf("You slam through a door and into the guard room.\n");
   printf("The two guards are slow moving, the eye level cloud \n");
   printf("would suggest Humbolt Green.\n");
   if(item == 'g')
   {
     printf("The two guards fumble over each other for their guns,\n");
     printf(" being careful not to drop the bong.\n");
     printf("But you waste them before they even squirm out of the couch.\n");
     printf("Lucky for you ,you wacked that guard.\n");
     do
     {
       fflush(stdin);
       printf("Now what?\n");
       gets(choices);
       fflush(stdin);

       if((strstr(choices,help)) != 0)
       {
	  printf("Enter: search or leave.\n");
	  error =1;
       }//help.
       if((strstr(choices,search)) != 0)
       {
	  error = 1;
	  printf("You scan the room and see a Pepsi machine.\n");
	  printf("Everything else looks like a dead end.\n");
	  printf("Do you want to buy a Pepsi?(y/n): ");
	  fflush(stdin);
	  scanf("%c",&choice);
	  fflush(stdin);
	  if(choice == 'y')
	      pepsi();
       }//if.
       else
       if((strstr(choices,leave)) != 0)
       {
	  error = 0;
	  lefthall();
       }//else.
       else
       if((strstr(choices,search)) == 0 || (strstr(choices,leave)) == 0 ||
	  (strstr(choices,help)) == 0)
       {
	  error = 1;
	  printf("Thats not an option...\n");
       }

     }while(error == 1);
   }//if.

   else
   if(item == 'y')
   {
     printf("You swing the statue at one of the guards, \n");
     printf("but miss him and hit the bong instead.\n");
     printf("Now your really going to die!\n");
     exit(0);
   }//else if.
   else
   {
     printf("The surprised guards begin to laugh histerically.\n");
     printf("You turn to run away but run into a guard with a .45\n");
     printf("He appears to have been sleeping across the hall,\n");
     printf("that is until your helpful friends woke him up.\n");
     exit(0);
   }//else.
}//coffeeroom.

void hallway(void)
{
  int error = 1;
  char choices[SIZE];
  char *restroom="restroom";
  char *second="second";
  char *end="end";
  char *back="back";

  clrscr();//system("clear");
  printf("The hallway stretches off in front of you.\n");
  printf("There are two doors along the left wall.\n");
  printf("The first one says restrooms on it.\n");
  printf("The seconds' sign seems to be torn off.\n");
  printf("The end of the hall seems to dead end...\n");
  do
  {
    printf("What do you do?\n");
    fflush(stdin);
    gets(choices);
    fflush(stdin);

    if((strstr(choices,help)) != 0)
    {
      printf("Enter: restroom, second, end, or back.\n");
      error = 1;
    }//help.
    if((strstr(choices,restroom)) != 0)
    {
       error = 0;
       toilet();
    }//if restroom.
    else
    if((strstr(choices,second)) != 0)
    {
       error = 0;
       secondroom();
    }//if second.
    else
    if((strstr(choices,end)) != 0)
    {
       error = 0;
       endhall();
    }//if end.
    else
    if((strstr(choices,back)) != 0)
    {
       error = 0;
       righthall();
    }//if back.
    else
    if((strstr(choices,restroom)) == 0 || (strstr(choices,second)) == 0 ||
       (strstr(choices,end)) == 0 || (strstr(choices,back)) == 0 ||
       (strstr(choices,help)) == 0)
    {
       error = 1;
       printf("I dont think that's too smart!\n");
    }//if else.

  }while(error == 1);
}//hallway.

void toilet(void)
{
   int error = 1;
   char choices[SIZE];
   char *leave="leave";
   char *toilets="toilets";
   char *shower="shower";
   char *sink="sink";
   char *drain="drain";

   clrscr();//system("clear");
   printf("You're standing in the middle of the restroom.\n");
   printf("To your right are 4 toilet stalls.\n");
   printf("To your left is a large, open shower area.\n");
   printf("In front of you is a counter with three sinks.\n");
   printf("Below you is a drain with something glimmering in it.\n");
   do
   {
      printf("What to do now...\n");
      fflush(stdin);
      gets(choices);
      fflush(stdin);

      if((strstr(choices,help)) != 0)
      {
	printf("Enter: leave, toilets, shower, sink, or drain.\n");
	error = 1;
      }//help.
      if((strstr(choices,leave)) != 0)
      {
	error = 0;
	hallway();
      }//if leave.
      else
      if((strstr(choices,toilets)) != 0)
      {
	error = 1;
	printf("They smell.\n");
      }//if toilets.
      else
      if((strstr(choices,shower)) != 0)
      {
	error = 1;
	printf("There's three shower heads & two drains in a tile floor.\n");
	printf("Close inspection shows that it's extremely dirty,\n");
	printf("but not much help to you.\n");
      }//if shower.
      else
      if((strstr(choices,sink)) != 0)
      {
	error = 1;
	printf("They appear to be dusty and hardly used.\n");
	sleep(2);
	printf("...and another dead end.\n");
      }//if sink.
      else
      if((strstr(choices,drain)) != 0)
      {
       error = 1;
       if(bar == 'b')
       {
	printf("You pull out the crowbar and begin ");
	printf(" to pry the drain loose.\n");
	printf("However you discover nothing more than");
	printf(" a nice shinny quarter.\n");
	printf("Maybe you can buy a Pepsi in the guard lounge.\n");
       }//if bar=b.
       else
       {
	printf("Close inspection reviles nothing. The screws are \n");
	printf("rusted in. You'll need to get something to pry it open.\n");
       }//else bar=n.
      printf("Better keep looking.\n");
      }//if drain.
      else
      if((strstr(choices,drain)) == 0 || (strstr(choices,sink)) == 0 ||
	 (strstr(choices,shower)) == 0 || (strstr(choices,toilets)) == 0 ||
	 (strstr(choices,leave)) == 0 || (strstr(choices,help)) == 0)
      {
	  error = 1;
	  printf("uuuhhhh...NO.\n");
      }//if else.
   }while(error == 1);
}//toilet.

void secondroom(void)
{
  int error = 1;
  char choices[SIZE];
  char *hubcap="hubcap";
  char *crowbar="crowbar";
  char *cupboards="cupboards";
  char *leave="leave";

  clrscr();//system("clear");
  printf("You open the door and discover what was once a storage facility.\n");
  printf("But now seems to have been cleaned out for some reason.\n");
  printf("The only thing you can see is a crowbar & hubcap on a countertop,\n");
  printf("and three locked cupboards on the opposite side.\n");
  do
  {
     printf("What now o' intelligent one...\n");
     fflush(stdin);
     gets(choices);
     fflush(stdin);

    if((strstr(choices,help)) != 0)
    {
      printf("Enter: hubcap, crowbar, cupboards, or leave.\n");
      error = 1;
    }//help.
     if((strstr(choices,cupboards)) != 0)
     {
       if(bar == 'h')
       {
	 printf("You try banging on the locks with the hubcap,\n");
	 printf("making a lot of noise, but not much else.\n");
	 printf("Better hope nobody heard you!\n");
       }//if bar=h.
       else
       if(bar == 'b')
       {
	 printf("You try prying the locks with the crowbar,\n");
	 printf("But they're brand new Master Locks, and wont budge.\n");
       }//if bar=b.
     error=1;
     }//if cupboards.
     else
     if((strstr(choices,crowbar)) != 0)
     {
       if(bar == 'h')
       {
	 printf("You put down the hubcap and pick up the crowbar ");
	 printf("and tuck it in your jacket\n");
	 printf("One can only carry so much...\n");
	 bar = 'b';
       }//if bar=h.
       else
       {
	 printf("You pickup the crowbar and tuck it in your jacket.\n");
	 bar = 'b';
       }//else.
     error=1;
     }//if crowbar.
     else
     if((strstr(choices,hubcap)) != 0)
     {
       if(bar == 'b')
       {
	 printf("You put down the crowbar and pick up the hubcap ");
	 printf("and tuck it in your jacket.\n");
	 printf("One can only carry so much...\n");
	 bar = 'h';
       }//if bar=b.
       else
       {
	 printf("You pick up the hubcap and tuck it in your jacket.\n");
	 printf("You never know what will come in handy.\n");
	 bar = 'h';
       }//else.
     error=1;
     }//if hubcap.
     else
     if((strstr(choices,leave)) != 0)
     {
       error = 0;
       hallway();
     }//if leave.
     else
     if((strstr(choices,leave)) == 0 || (strstr(choices,hubcap)) == 0 ||
	(strstr(choices,crowbar)) == 0 || (strstr(choices,cupboards)) == 0 ||
	(strstr(choices,help)) == 0)
     {
	printf("Try again bright boy!\n");
	error = 1;
     }//else if.
  }while(error == 1);
}//secondroom.

void endhall(void)
{
  int error = 1;
  char choices[SIZE];
  char *back="back";
  char *gun="gun";
  char *attack="attack";
  char *surrender="surrender";

  if(leiut != 'd')
  {
   clrscr();//system("clear");
   printf("As you reach the end of the hall, you realize that a curio\n");
   printf("placed part way around the corner made it only appear to be\n");
   printf("a dead end, so you quickly run around the corner.\n");
   printf("but stop even quicker when the Lieutenant on the other end\n");
   printf("catches your eye.\n");
   printf("The officer starts to go for his gun...\n");

   do
   {
     printf("Quick! What do you do?\n");
     fflush(stdin);
     gets(choices);
     fflush(stdin);

    if((strstr(choices,help)) != 0)
    {
      printf("Enter: back, attack, gun, or surrender.\n");
      error = 1;
    }//help.
     if((strstr(choices,back)) != 0)
     {
       error = 0;
       printf("You turn and run back to the hall you came from,\n");
       if(item == 'g')
	 printf("Completely forgetting about your gun and other stuff,\n");
       printf("unfortunately for you this guy has no problem shooting\n");
       printf("someone in the back. And you slam into the wall across\n");
       printf("the hall, making an extremely bloody mess.\n");
       printf("Next time don't be such a chicken!");
       exit(0);
     }//if back.
     else
     if((strstr(choices,gun)) != 0)
     {
       error=0;
       printf("You raise your gun, but the officer is much faster than you,\n");
       printf("and you go flying back from the slug that hits your gut.\n");
       if(bar == 'h')
       {
	 printf("But fortunately the hubcap in your jacket catches the worst\n");
	 printf("of the blow, and when the officer comes to glare over you,\n");
	 printf("you blow his head all over the ceiling.\n");
	 sleep(3);
	 printf("But the gunshots brig two guards running from the other\n");
	 printf("end of the hall and your victory becomes short lived.\n");
	 printf("The guards decide you're not worthy of bullets,\n");
	 printf("and merely crush your skull with the butts of their guns.\n");
	 exit(0);
       }
       else
       {
	 printf("as you lay on the floor with a slow death wound,\n");
	 printf("you live just long enough to see the guard standing\n");
	 printf("over you grinning before everything goes black.\n");
	 exit(0);
       }
     }//if gun.
     else
     if((strstr(choices,attack)) != 0)
     {
       error=0;
       if(item == 'g')
       {
       printf("You run balls out toward the guard pumping shell after\n");
       printf("shell into him, but this is a lieutenant and has much\n");
       printf("more experience than you. By the time you fall to the\n");
       printf("floor together he only has half the slugs in him you do.\n");
       printf("At least you went with a 'bang'.\n");
       exit(0);
       }
       else
       {
       printf("You've lost all control and go flying toward the guard,\n");
       printf("and a single shot lays you out.\n");
       printf("Next time bring a gun to a gun fight.\n");
       exit(0);
       }
     }//if attack.
     else
     if((strstr(choices,surrender)) != 0)
     {
       if(item=='g')
       {
	 printf("Your hands go up and the gun goes to the floor.\n");
	 if(bar=='b')
	 {
	   error = 0;
	   printf("The guard comes up to escort you to your room again,\n");
	   printf("but when he puts his gun away to cuff you,\n");
	   printf("you pull out the crowbar and slam it in his throat.\n");
	   printf("After admiring your work for a minute or two,\n");
	   printf("you drag the body over behind the curio out of the way.\n");
	   sleep(8);
	   leiut = 'd';
	   deadguard();
	 }//if bar=b.
	 else
	 if(bar=='h')
	 {
	   printf("The guard comes up to escort you to your room again,\n");
	   printf("but when he puts his gun away to cuff you,\n");
	   printf("you pull out the hubcap and knock him over the head,\n");
	   printf("many,many,many times, until he finally dies.\n");
	   printf("After admiring your work for a minute or two,\n");
	   printf("you drag the body over behind the curio out of the way.\n");
	   sleep(6);
	   leiut = 'd';
	   deadguard();
	 }//if bar=h.
	 else
	 {
	   printf("The guard gives you a smack on the back of the head,\n");
	   printf("as he cuffs and takes you to your room again.\n");
	   bar = 'n';
	   item = 'n';
	   key = 'n';
	   error = 0;
	   sleep(4);
	   door();
	 }//else.
       }//if item=g.
       else
       if(bar=='b' && item!='g')
       {
	 printf("The guard comes to put the cuffs on you and escort you\n");
	 printf("to your room but when his gun goes down your crowbar\n");
	 printf("comes out and he goes down.(Van Dam eat your heart out!)\n");
	 sleep(4);
	 leiut = 'd';
	 deadguard();
       }//if crowbar.
       else
       {
	 printf("The guard gives you a smack on the back of the head,\n");
	 printf("as he cuffs and takes you to your room again.\n");
	 bar = 'n';
	 item = 'n';
	 key = 'n';
	 error = 0;
	 sleep(4);
	 door();
       }//else.
     }//if surrender.
     else
     if((strstr(choices,back)) == 0 || (strstr(choices,gun)) == 0 ||
	(strstr(choices,attack)) == 0 || (strstr(choices,surrender)) == 0 ||
	(strstr(choices,help)) == 0)
     {
	printf("Not an option dummy.\n");
	error = 1;
     }//if else.
   }while (error == 1);
  }//if leiut.
  else
  {
    printf("Your standing in the corner over the dead guards body.\n");
    printf("What now?\nGo back further?\n");
    fflush(stdin);
    gets(choices);
    fflush(stdin);

    if((strstr(choices,back)) != 0)
       hallway();

    else
       deadguard();

  }//else guard dead.
}//endhall.

void deadguard(void)
{
  int error=1;
  char choices[SIZE];
  char *gexit="exit"; char *right="right";
  char *back="back";
  char *door="door"; char *left="left";
  char *attack="attack"; char *kill="kill";
  char *dead="dead";

  clrscr();//system("clear");
  printf("You leave the guard slumped on the wall and go running down the\n");
  printf("hall, only to duck back in and slam against the wall when you see\n");
  printf("the room full of guards, it looks like a command center.\n");
  printf("\nA couple of yards in front of the opening of the hallway is \n");
  printf("a large desk with three terminals and three techs. In front and \n");
  printf("to the left is another desk with another tech. To the right is \n");
  printf("the communications desk and another tech.(all techs are armed!)\n");
  printf("Down front and center is the main General, standing in front \n");
  printf("of a large display screen showing how they intend to end \n");
  printf("the world! Just to your immediate left is a door, and\n");
  printf("even more important the EXIT just to your right!\n");
  do
  {
    printf("So do we bolt, save the world, or what?\n");
    fflush(stdin);
    gets(choices);
    fflush(stdin);

    if((strstr(choices,help)) != 0)
    {
      printf("Enter: exit, right, door, left, attack, kill, dead guard, or back.\n");
      error = 1;
    }//help.
    if((strstr(choices,back)) != 0)
    {
      error = 0;
      endhall();
    }//if back.
    else
    if((strstr(choices,gexit)) != 0 || (strstr(choices,right)) != 0)
    {
      error = 0;
      if(key == 'k')
      {
	printf("You slide out from your hiding place and around\n");
	printf("the corner to the exit, and squish against the wall.\n");
	printf("The door is locked but you swiped those keys.\n");
	printf("Enjoy your last few remaining days, coward!\n");
	exit(0);
      }
      else
      {
	printf("You slowly go for the exit, but its locked!\n");
	printf("And you end up with 4 techs and 1 General pumping\n");
	printf("lead in your sorry ass, before you can even turn around.\n");
	printf("\nThats what you get for being a coward!\n");
	exit(0);
      }
    }//if exit/right.
    else
    if((strstr(choices,dead)) != 0)
    {
      error = 1;
      printf("You run to the dead guard at the other end of the hall,\n");
      printf("and begin rummaging around his pockets...\n");
      printf("You find a clip perfect for your gun, a set of keys, \n");
      printf("and a picture of the guard and his family...\n");
      sleep(3);
      printf("You keep the clip and keys, tossing the photo aside.\n");
      key = 'k';
    }//if dead.
    else
    if((strstr(choices,kill)) != 0 || (strstr(choices,attack)) != 0 )
    {
      error = 0;
      if(item == 'g')
      {
	printf("You pull your gun and blow the center technicians\n");
	printf("head all over his screen, you manage to pick off two more\n");
	printf("before the others lay you out.\n");
	printf("A valiant effort.\n");
	exit(0);
      }
      else
      if(bar == 'b')
      {
       printf("You dive for the center technician directly in front of you,\n");
       printf("swinging the crowbar and merging his head with his monitor.\n");
       printf("A quick yank and the crowbar is free of his skull, and you\n");
       printf("swing just in time to slice the techs teeth out of his mouth\n");
       printf("along with half his face with the tip of the crowbar,\n");
       printf("as he's backing away and going for his gun. Unfortunatly,\n");
       printf("your not quick enough to get to the rest before your body\n");
       printf("becomes to heavy to move from all the lead that's in it.\n");
       printf("A valiant effort.\n");
       exit(0);
      }
      else
      if(grand == 'y')
      {
	printf("You toss the genades in several parts of the room.\n");
	if(item == 'g')
	{
	   printf("You take out your gun and begin blasting anything\n");
	   printf("that moves.\n");
	}
	printf("After the dust settles, you realize you've killed\n");
	printf("everything in the building except the plant in the corner.\n");
	printf("\nBetter buy yourself a beer, you deserve it!\n");
	exit(0);
      }//if grand.
    }//if attack/kill.
    else
    if((strstr(choices,door)) != 0 || (strstr(choices,left)) != 0)
    {
       error = 0;
       clrscr();//system("clear");
       printf("\n\nYou slowly back your way toward the door,\n");
       printf("and behind a large fern like plant.\n");
       sleep(3);
       armory();
    }//if door/left.
    else
    if((strstr(choices,right)) == 0 || (strstr(choices,left)) == 0 ||
       (strstr(choices,door)) == 0 || (strstr(choices,gexit)) == 0 ||
       (strstr(choices,attack)) == 0 || (strstr(choices,kill)) == 0 ||
       (strstr(choices,back)) == 0 || (strstr(choices,dead)) == 0 ||
       (strstr(choices,help)) == 0)
    {
       printf("That's not an option I'd suggest.\n");
       error = 1;
    }//if else.
  }while(error == 1);
}//deadguard.

void armory(void)
{
  int error = 1;
  char choices[SIZE];
  char *attack="attack";
  char *door="door";
  char *back="back";

  printf("\nA sign on the door says armory...\n");
  printf("You try the door and realize its locked.\n");
  do
  {
  printf("What do you do?\n");
  fflush(stdin);
  gets(choices);
  fflush(stdin);

    if((strstr(choices,help)) != 0)
    {
      printf("Enter: attack, door, or back.\n");
      error = 1;
    }//help.
  if((strstr(choices,door)) != 0)
  {
    if(key == 'k')
    {
     printf("You quietly pull the keys out and unlock the door.\n");
     printf("After slowly slipping in you close the door and turn around.\n");
     printf("The room is full of guns, and you run straight to the biggest\n");
     printf("gun you can see, but realize there are no clips. As you\n");
     printf("search more guns you realize all the ammo is obviously kept\n");
     printf("else where! So you move on to some open crates that are full\n");
     printf("of packing and discover some grenades! These dont need ammo...\n");
     printf("You pick up as many as you can carry. And return outside.\n");
     error = 1;
     grand = 'y';
    }//keys.
    else
    if(key == 'y')
    {
      printf("You try to pick the lock with the wire but its too\n");
      printf("sophisticated a lock. You need the key.\n");
      error = 1;
    }//wire.
  }//if door.
  else
  if((strstr(choices,attack)) != 0)
  {
   if(grand == 'y' && item == 'g')
   {
     printf("You  pull the pins on all the grenades, tossing them\n");
     printf("the ring of desks in various places. After the first one\n");
     printf("goes you start pumping lead into anything that moves.\n");
     sleep(6);
     printf("After the dust settles the only thing moving is the fuz\n");
     printf("on the 'holy' screen bouncing around. You look like shit,\n");
     printf("but you did it!\n\n");
     printf("Go buy yourself a beer, you deserve it...\n");
     error = 0;
     exit(0);
   }// if grand.
   else
   if(item == 'g')
   {
     printf("From this vantage point you have a clear shot at the General,\n");
     printf("and you take it. You've foiled his plans but the others end\n");
     printf("up shortening you life considerably.\n\n");
     printf("The worlds safe for now, too bad you can't enjoy it.\n");
     error = 0;
     exit(0);
   }//if gun.
   else
   {
     printf("You go balls out at the first person you see...");
     printf("and quickly get laid out by a tech who barely flinches.\n");
     printf("Dumb ass...\n");
     error = 0;
     exit(0);
   }//else.
  }//if attack.
  else
  if((strstr(choices,back)) != 0)
  {
    printf("You start to make your way back to the hall...\n");
    sleep(3);
    error = 0;
    deadguard();
  }//if back.
  else
  if((strstr(choices,attack)) == 0 || (strstr(choices,door)) == 0 ||
     (strstr(choices,back)) == 0 || (strstr(choices,help)) == 0)
  {
    printf("That's not right.\n");
    error = 1;
  }//else if.

  }while(error == 1);
}//armory.

int pepsi(void)
{
   char choice,another='y';
   int total=0;

   do
   {
     total = 0;
   do
   {
      choice = menu(choice);

	switch(choice)
	{
	   case '1':total+=5;
		    break;
	   case '2':total+=10;
		    break;
	   case '3':total+=25;
		    break;
	   case '4':if(total>0){
		      printf("Sorry, you cant put in a dollar after change\n");
		      sleep(3);
		      break;
		    }
		    else{
		      total+=100;
		      break;
		    }
	   case 'q':printf("Thanks, and enjoy your caffeine,");
		    printf(" it may be your last.\n");
		    lefthall();
	   default :printf("We dont take that!");
		    sleep(2);
	}//switch.
   if(total<55)
   {
     printf("You owe us %d cents.\n",55-total);
     sleep(2);
   }//if.
   } while(total < 55);

   if(total>55)
     change(total);

   printf("Would you like another of our fine bounty?");
   fflush(stdin);
   scanf("%c",&another);
   }while(another != 'n');

   return 0;
}//pepsi.

int change(total)
{
   int change,nickles,dimes,quarters;

   change = total-55;
   quarters = change/25;
   dimes = change%25/10;
   nickles = change%25%10/5;
   printf("Your change is %d quarters, %d dimes, and %d nickles\n",
			     quarters,dimes,nickles);
   sleep(3);
return 0;
}

char menu(char choice)
{
	clrscr();//system("clear");
	printf("Pepsi the choice...\n");
	printf("       oooooooooooo\n");
	printf("     o         )ooooo\n");
	printf("    o         )ooooooo\n");
	printf("    o        )ooooooooo\n");
	printf("    o      (ooooooooooo\n");
	printf("     o    (ooooooooooo\n");
	printf("      o   (oooooooooo\n");
	printf("        oooooooooooo \n");
	printf("Please enter...\n");
	printf("1) nickels 2) dimes 3) quarters\n");
	printf("4) a dollar or q) quit\n");
	fflush(stdin);
	scanf("%c",&choice);
	return choice;
}//menu.

