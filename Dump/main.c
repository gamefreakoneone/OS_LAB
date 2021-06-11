/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <string.h>
int i;
struct bus
{
  char driver;
  char busno;
  float atime;
  float dtime;
  char from;
  char to;
  int seats[8][4][10];
};
struct bus b[10];
struct bus b1[10], b2[10];

void admin();
void addbus();
void avail();
void delete ();
void customer();
void show();
void reserve();
void position();

void admin()
{

  int choice;
top:
  printf("Enter ur choice: 1-Add bus 2-show bus details 3-delete 4-exit\n");
  scanf("%d", &choice);
  switch (choice)
  {
  case 1:
    addbus();
    break;

  case 2:
    avail();
    break;

  case 3:
    printf("delete");
    break;

  case 4:
    main();
    break;

  default:
    printf("Enter valid choice");
    break;
  }
  goto top;
}

void addbus()
{

  int i = 0;
  int d;
  while (i <= 1)
  {
    printf("Enter driver name,busno,arrival time,departure time,from,to and no. of seats\n");
    scanf("%c %c %f %f %c %c %d", &b[i].driver, &b[i].busno, &b[i].atime, &b[i].dtime, &b[i].from, &b[i].to, &b[i].seats);
    while ((d = getchar()) != '\n')
      ;
    while (d != '\n')
      d = getchar();
    i++;
  }
}

void avail()
{
  int i;
  b1[10] = b[10];
  printf("%c %c %f %f %c %c %d\n", b[i].driver, b[i].busno, b[i].atime, b[i].dtime, b[i].from, b[i].to, b[i].seats);
}

void customer()
{
  int choice;

options:
  printf("Enter your choice: 1- Available buses 2-empty seats 3-reservation 4-exit\n");
  scanf("%d", &choice);
  switch (choice)
  {
  case 1:
    avail();
    break;

  case 2:
    show();
    break;

  case 3:
    reserve();
    break;

  case 4:
    main();
    break;

  default:
    printf("Enter valid choice");
    break;
  }
  goto options;
}

void show()
{
  char number;
  printf("Enter Bus no.\n");
  scanf("%c", &number);
  int n;
  for (n = 0; n <= i; n++)
  {
    if (strcmp(b[i].busno, number) == 0)
      break;

    while (n <= i)
    {
      printf("Driver name: %c\t\t bus number:%c\t\t arrival time:%f\t\n departure time:%f\t\t from:%c\t\t to:%c\t\t", b[i].driver, b[i].busno, b[i].atime, b[i].dtime, b[i].from, b[i].to);
      position(b);
      int a = 1;

      for (int r = 0; r < 8; r++)
      {
        for (int c = 0; c < 4; c++)
        {
          a++;
          if (strcmp(b[n].seats[r][c], "Empty") != 0)
            printf("The seat no. %d is reserved", a - 1);
        }
      }
      break;
      if (n > i)
        printf("Enter correct bus number");
    }
  }
}

void position(int l)

{

  int s = 0;
  int p = 0;

  for (int r = 0; r < 8; r++)

  {

    printf("\n");

    for (int c = 0; c < 4; c++)

    {

      s++;

      if (strcmp(b[l].seats[r][c], "Empty") == 0)

      {
        printf("%.5d . %.5d", s, b[l].seats[r][c]);

        p++;
      }

      else

      {
        printf("%.5d . %.5d", s, b[l].seats[r][c]);
      }
    }
  }

  printf("\n\nThere are %d seats empty in Bus No:%d", p, b[l].busno);
}

void reserve()
{
  char number;
  int seat;

allot:

  printf("Enter Bus no.\n");
  scanf("%c", &number);
  int n;
  for (n = 0; n <= i; n++)
  {
    if (strcmp(b[i].busno, number) == 0)
      break;
  }
  while (n <= i)

  {

    printf("\nSeat Number");
    scanf("%d", seat);

    if (seat > 32)
    {
      printf("\nThere are only 32 seats available in this bus.");
    }

    else

    {

      if (strcmp(b[n].seats[seat / 4][(seat % 4) - 1], "Empty") == 0)

      {

        printf("Enter passanger's name: ");

        scanf("%d", &b[n].seats[seat / 4][(seat % 4) - 1]);

        break;
      }

      else

        printf("The seat no. is already reserved.\n");
    }
  }

  if (n > i)

  {

    printf("Enter correct bus no.\n");

    goto allot;
  }
}

void main()
{
  int ch;
  char uname[10];
  char password[10];

login:

  printf("Enter your choice: 1- Admin 2-Customer\n");
  scanf("%d", &ch);
  char user1[] = "kapil", user2[] = "kishore", user3[] = "kanchan";
  char pass1[] = "k1", pass2[] = "k2", pass3[] = "k3";

  if (ch == 1)
  {
    printf("Enter username\n");
    scanf("%s", &uname);
    printf("Enter password\n");
    scanf("%s", &password);

    if (strcmp(uname, user1) == 0 && strcmp(password, pass1) == 0)
    {
      printf("Login successful\n");
      admin();
    }

    if (strcmp(uname, user2) == 0 && strcmp(password, pass2) == 0)
    {
      printf("Login successful\n");
      admin();
    }

    if (strcmp(uname, user3) == 0 && strcmp(password, pass3) == 0)
    {
      printf("Login successful\n");
      admin();
    }

    else
    {
      printf("Incorrect username or password");
      goto login;
    }
  }
  else if (ch == 2)
  {
    customer();
  }
  else
  {
    printf("Enter valid choice");
  }
}
