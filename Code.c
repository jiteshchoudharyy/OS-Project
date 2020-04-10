#include<stdio.h>
int main()
{
char auth, queuetype;
int i, lim, total = 0, x, counter = 0, timequantum;
int waittime = 0, turnaroundtime = 0, arrivaltime[10], bursttime[10], temp[10];
float averagewaittime, avgturnaroundtime;
scanf("%c", &auth);
switch(auth)
{
case 'Y':
case 'y':
printf("\nSelect the type of queue :\n  1 = Student\n  2 = Teacher\n==> ");
scanf("%d", &queuetype);
if (queuetype == 1)
printf("\nSelected Student Queue!");
else printf("\nSelected Teacher Queue!");
printf("\nEnter Total Number of Processes:\t");
scanf("%d", &lim);
x = lim;
for(i = 0; i < lim; i++)
{
printf("\nEnter Details of Process[%d]\n", i + 1); 
printf("Arrival Time:\t"); 
scanf("%d", &arrivaltime[i]);
printf("Burst Time:\t"); 
scanf("%d", &bursttime[i]); 
temp[i] = bursttime[i];
}
printf("\nEnter Time Quantum:\t");
scanf("%d", &timequantum);
printf("\nProcess ID\t\tBurst Time\t Turnaround Time\t Waiting Time\n");
for(total = 0, i = 0; x != 0;)
{
if(temp[i] <= timequantum && temp[i] > 0)
{
total = total + temp[i];
temp[i] = 0;
counter = 1;
}
else if(temp[i] > 0)
{
temp[i] = temp[i] - timequantum;
total = total + timequantum;
}
if(temp[i] == 0 && counter == 1)
{
x--;
printf("\nProcess[%d]\t\t%d\t\t %d\t\t\t %d", i + 1, bursttime[i], total - arrivaltime[i], total - arrivaltime[i] - bursttime[i]);
waittime = waittime + total - arrivaltime[i] - bursttime[i];
turnaroundtime = turnaroundtime + total - arrivaltime[i];
counter = 0;
}
if(i == lim - 1)
{
i = 0;
}
else if(arrivaltime[i + 1] <= total)
{
i++;
}
else
{
i = 0;
}
}
averagewaittime = waittime * 1.0 / lim;
avgturnaroundtime = turnaroundtime * 1.0 / lim;
printf("\n\n\nTotal Query Time:\t%f", turnaroundtime * 1.0);
printf("\nAverage Query Time:\t%f", avgturnaroundtime);
printf("\nAverage Waiting Time:\t%f", averagewaittime);
return 0;
break;    
case 'n':
case 'N':
printf("\n\nSorry, You can't proceed because you are not authorized.\nTry again between 10AM & 12AM.");
break;      
default:
printf("\n\nWrong Input !!!\nClosing program...");
break;
}
}