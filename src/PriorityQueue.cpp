#include "PriorityQueue.h"
#include <iostream>

using namespace std;

PriorityQueue::PriorityQueue()
{
    length = 100000;
    n = 0;
    a = new PQElement[length];
}

PriorityQueue::PriorityQueue(int l)
{
    length = l;
    n = 0;
    position = new int[length];
    a = new PQElement[length];
}
/*
PriorityQueue::PriorityQueue(PQElement *e, int l)
{
    this->length = l;
    this->n = 0;
    this->a = e;
}
*/

PriorityQueue::~PriorityQueue()
{
    //dtor
}


PQElement& PriorityQueue::Minimum(void) const
{
    return this->a[1];
}

void PriorityQueue::upHeap(int i)
{

    //int x = i;
    while((i/2 > 0) && (this->a[i/2] > this->a[i])) { // Vorgaenger (i/2) vorhanden und groesser
        position[a[i].get_id()] = i/2;
		position[a[i/2].get_id()] = i;
		//cout << "Hallo " << position[a[i].get_id()] << endl;
		//cout << position[a[i/2].get_id()] << endl;

        vertausche(&a[i], &a[i/2]);
        i=i/2;
    }


/*
    int parentIndex = i / 2;
	if (a[i].get_prio() < a[parentIndex].get_prio())
	{
	    position[a[i].get_id()] = parentIndex;
		position[a[parentIndex].get_id()] = i;

		vertausche(&a[i], &a[parentIndex]);
		upHeap(parentIndex);
	}
	*/

}

/*
a0 solange mit dem groesseren seiner beider Nachfolger vertauscht,
bis a0 groesser als seine Nachfolger ist oder bis zu einem Blatt hinunter gewandert ist.
*/
void PriorityQueue::downHeap(int i)
{
    int l = 2*i;         //leftChildIndex, linker Nachfolger
    int r = l+1;       //rightChildIndex, rechter Nachfolger
    int minimum;

    if(l <= n && (a[l] < a[i]) ) {
        minimum = l;
    }
    else {
        minimum = i;
    }

    if(r <= n && (a[r] < a[minimum])) {
        minimum = r;
    }

    if(minimum != i) {
         position[a[i].get_id()] = minimum;
		 position[a[minimum].get_id()] = i;

         vertausche(&a[i], &a[minimum]);
         downHeap(minimum);
    }
}


PQElement PriorityQueue::Extract_Min(void)
{
    PQElement element = Minimum();
    this->a[1] = this->a[n]; // letztes Element als Wurzel
    this->n -= 1; // aktuelle Laenge runterzaehlen
    downHeap(1); // aktuelle Position uebergeben
    return element;

    /*
    vertausche(&a[1], &a[n]);
    //this->n -= 1;
	downHeap(1);
	return a[n--];
	*/
}

void PriorityQueue::Insert(PQElement anew)
{
    this->a[n+1] = anew;
    position[anew.get_id()] = n+1;
    this->n += 1; // aktuelle Laenge hochzaehlen
    upHeap(n);

    /*
    a[n+1] = anew;
	upHeap(n++);
	*/
}

void PriorityQueue::increase(int id, int d)
{
    //int stelle = suche(id);
	int stelle = position[id];

	if(stelle != -1){
		if (d > 0)
		{
			a[stelle].set_prio(a[stelle].get_prio() + d);
			downHeap(stelle);
		}
		else if (d < 0)
		{
			a[stelle].set_prio(a[stelle].get_prio() + d);
			upHeap(stelle);
		}
	}
}

void PriorityQueue::loeschen(int id)
{
    //int stelle = suche(id);
    int stelle = position[id];

    vertausche(&a[stelle], &a[n]); // zu loeschendes element ans ende verschieben
    downHeap(stelle);
    this->n -= 1;
}

int PriorityQueue::suche(int id)
{
    int i = 1;
    while(i <= n && id != a[i].get_id()){
        i++;
    }
    return (i);
}

void PriorityQueue::vertausche(PQElement *a, PQElement *b)
{
    //cout << "vertausche Prio " << a->get_prio() << " mit Prio " << b->get_prio() << endl;
    PQElement temp = *a;
    *a = *b;
    *b = temp;
}

void PriorityQueue::ausgeben()
{
    cout << "\nausgeben(): " << endl;
    for(int i = 1; i <= n; i++){
        cout  << "Position: " << position[a[i].get_id()] << ", ID: " << this->a[i].get_id() << ", Prio: " << this->a[i].get_prio() << endl;
    }
}
