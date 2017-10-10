#include <stdbool.h>
#include <stdio.h>
//Załadowanie dwóch potrzebnych nagłówków
//stdbool.h do obsługi typu zmiennej BOOL
//stdio.h do obsługi funkcji printf()

//Ciąg zmiennych do przesortowania
int array[] = {3,1,4,6,2,7,9,8,5};
//Zmienna potrzebna by móc przechowywać wartość liczby do zamienienia.
int temp1;
//Standardowe C nie posiada typu BOOL, więc można załadować stdbool.h lub stworzyć int do którego będzie przypisywana wartośc od 1 do 0.
bool posortowane;

int main()
{
    //wyliczenie które ma na celu wykonanie tyle razy ile jest liczb w ciągu zadeklarowanym na początku
    for (unsigned int j = 0; j < ((sizeof(array) / sizeof(*array) - 1)); j++) {
        //ustawiamy wartość posortowane na true i gdy posiadamy coś do posortowania zmieniamy na false by zatrzymać program po posortowaniu.
        posortowane = true;
        //kolejne wyliczenie mające na celu zamiane liczb tyle razy ile jest liczb w ciągu minus 1
        for (unsigned int i = 0; i < ((sizeof(array) / sizeof(*array) - 1)); i++) {
            if (array[i] > array[i + 1]) {
                //przypisujemy wartość pierwszej liczby do wartości tymczasowej
                temp1 = array[i];
                //pierwsza wartość staje się drugą wartością
                array[i] = array[i + 1];
                //druga wartość staje wartością tymczasową
                array[i + 1] = temp1;
                //ustawiamy wartość na false ponieważ nie jest posortowane bo wykonaliśmy sortowanie
                posortowane = false;
            }
        }
        //jeśli posortowane to przerwij pętle
        if (posortowane) break;
        //wypisanie kroków po koleji i zawartości ciągu w każdym kroku
        printf("Krok[%d] ",j+1);
        for (unsigned int k = 0; k < ((sizeof(array) / sizeof(*array) - 1)); k++)
        {
            printf("%d",array[k]);
        }
        printf("\n");
    }
    return 0;
}
