#include <stdio.h>
#include<time.h>
#include<stdlib.h>

int main()
{
    int rok, miesiac, dzien;
    int i;
    int kolejne_pelnie;
    int poprzednie_pelnie;
    FILE *plik;
   printf("Kiedy byla ostatnia pelnia ? (DD.MM.YYYY): ");
    scanf("%d.%d.%d",&dzien,&miesiac,&rok);
    
    int data[] = {dzien,miesiac,rok};
    plik = fopen("log.txt","w");
    fprintf(plik,"Data ostatniej pełni: %d.%d.%d",data[0],data[1],data[2]);
    
    //weryfikacja daty
     
   if(rok>=0)
    {
        if(miesiac>=1 && miesiac<=12)
        {
            if((dzien>=1 && dzien<=31) && (miesiac==1 || miesiac==3 || miesiac==5 || miesiac==7 || miesiac==8))
            {
                printf("Poprawna data. %d.%02d.%d\n",dzien,miesiac,rok);
            }
            else if((dzien>=1 && dzien<=31) && (miesiac==10 || miesiac==12))
            {
                printf("Poprawna data. %d.%d.%d\n",dzien,miesiac,rok);
            }
            else if((dzien>=1 && dzien<=30) && (miesiac==4 || miesiac==6 || miesiac==9))
            {
                printf("Poprawna data. %d.%02d.%d\n",dzien,miesiac,rok);
            }
            else if((dzien>=1 && dzien<=30) && miesiac==11)
            {
                printf("Poprawna data. %d.%d.%d\n",dzien,miesiac,rok);
            }
            else if((dzien>=1 && dzien<=28) && miesiac==2)
            {
                printf("Poprawna data. %d.%02d.%d\n",dzien,miesiac,rok);
            }
            else if(dzien==29 && miesiac==2 && (rok%400==0 ||(rok%4==0 && rok%100!=0)))
            {
                printf("Poprawna data. %d.%02d.%d\n",dzien,miesiac,rok);
            }
            else
            {
                printf("Liczba dni w miesiacu jest bledna.\n");
                return 0;
            }
        }
        else
        {
            printf("Nie ma takiego miesiaca.\n");
            return 0;
        }
    }
    
    printf("Jezeli chcesz wyliczyc daty kolejnych pelni uzyj k.");
    printf("\nNatomiast jeżeli wolisz zobaczyc daty poprzednich pelni wybierz p.\n");

    char wybor;
    scanf(" %c", &wybor);
    
    //struktura czasu
    struct tm  t = {
                    .tm_mday = dzien,
                    .tm_mon = miesiac-1,
                    .tm_year = rok-1900,
                    };
    int skip = 29;
    char buffer[15];
    
    //wybor użytkownika co chce zrobić
    switch(wybor)
    {
        default:
            printf("Zły znak.");
            break;
        case 'k':
        case 'K':
            printf("\nIle kolejnych pełni?\n");
            scanf("%d",&kolejne_pelnie);
                for(i=1;i<=kolejne_pelnie;i++)
                {
                    t.tm_mday += skip;
                    mktime(&t);
                    strftime(buffer, 15, " %d.%m.%Y", &t);
                    printf("%d pelnia:%s\n",i,buffer);
                    fprintf(plik,"\n%d pelnia:%s",i,buffer);
                }
                break;
        case 'p':
        case 'P':
            printf("\nIle poprzednich pełni?\n");
            scanf("%d",&poprzednie_pelnie);
            for(i=1;i<=poprzednie_pelnie;i++)
            {
                    t.tm_mday -= skip;
                    mktime(&t);
                    strftime(buffer, 15, " %d.%m.%Y", &t);
                    printf("%d pelnia:%s\n",i,buffer);
                    fprintf(plik,"\n%d pelnia:%s",i,buffer);
            }
            break;
                
    }
    
    fclose(plik);

    return 0;    
}