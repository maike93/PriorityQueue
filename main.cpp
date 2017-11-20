#include <iostream>
#include <vector>
#include "PQElement.h"
#include "PriorityQueue.h"
#include "Random.h"
#include <time.h>
#define N1 100000
#define N2 1000000
#define N3 5000000
using namespace std;

int main()
{
    int n = 20000;
    PriorityQueue pq1(n);

    Random r(n);
    for(int i=0; i < n; i++ ) {
        PQElement e; // temporaeres Hilfselement
        e.set_prio(r.give()); // prio zuweisen
        e.set_id(i+1); // id zuweisen
        pq1.Insert(e);
        //cout << "ID: " << e.get_id() << ", Prio: " << e.get_prio() << endl;
    }

    //cout << "\nPQ1 enthaelt: " << endl;
    //pq1.ausgeben();


    // Zeit messen
    PriorityQueue pqSorted(n); // andere PQ
    clock_t start = clock();
    for(int i = 0; i < n; i++){
        //cout << pq1.Extract_Min().get_id() << ", " << pq1.Extract_Min().get_prio() << endl;
        pqSorted.Insert(pq1.Extract_Min());
    }
    clock_t ende = clock();
    time_t time = ((ende-start)*1000)/CLOCKS_PER_SEC;
    cout << "Zeit zum Extract_Min: " << time << "ms" << endl;

    //pqSorted.ausgeben();


    // Aufgabe 2

    // Test
    pqSorted.increase(6, 10);
    pqSorted.loeschen(8);
    pqSorted.ausgeben();


  // testen, wenn Funktionen increase und loeschen funktionieren
    Random r3(n);
    clock_t start2 = clock();
    for(int i=0; i<n; i++ ) {
        if( i%2 == 0 ) pqSorted.loeschen(i);
        else pqSorted.increase(i, r.give()/2);
    }
    clock_t ende2 = clock();
    time_t time2 = ((ende2-start2)*1000)/CLOCKS_PER_SEC;
    cout << "Zeit zum Extract_Min: " << time2 << "ms" << endl;
    //pqSorted.ausgeben();

    int n2 = pqSorted.Size();
    PriorityQueue pq2(n2);

    for(int i = 0; i < n2; i++){
        pq2.Insert(pqSorted.Extract_Min());
    }
    pq2.ausgeben();

}
