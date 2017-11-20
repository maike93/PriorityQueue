#include "PQElement.h"

#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H


class PriorityQueue
{
    public:
        PriorityQueue();
        PriorityQueue(int l);
        //PriorityQueue(PQElement *e, int l);
        virtual ~PriorityQueue();
        int Size() {return n;};
        void ausgeben();
        void vertausche(PQElement *a, PQElement *b);
        PQElement& Minimum(void) const; /* Liefert a1 */
        PQElement Extract_Min(void); /* Sortieren = Liefert a1, l̈oescht a1, indem es mit a(n) vertauscht wird, Heap-Eigenschaft wieder herstellen (downHeap()) */
        void Insert(PQElement anew); /* Neues Element a0 bei n+1 einfügen, Vertausche a0 solange mit dem jeweiligen Vorgaeger bis die Heap-Eigenschaft wieder hergestellt ist (upHeap()) */
        void downHeap(int i);
        void upHeap(int i);
        void increase(int id, int d);
        void loeschen(int id);
        int suche(int id);
    protected:
    private:
        int n; /* aktuelle Laenge */
        int length; /*Gesamtlaenge=Aufnahmekapazitaet*/
        PQElement *a;/* fuer das Feld */
        int *position;
};

#endif // PRIORITYQUEUE_H
