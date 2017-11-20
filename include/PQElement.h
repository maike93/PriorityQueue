#ifndef PQELEMENT_H
#define PQELEMENT_H


class PQElement
{
    public:
        PQElement();
        virtual ~PQElement();
        int get_prio(void) const { return prio; }
        void set_prio(int p) { prio = p; }
        int get_id(void) const { return id; }
        void set_id(int i) { id = i; }
        bool operator> (const PQElement& e) const{
            return prio > e.prio;
        }
        bool operator< (const PQElement& e) const{
            return prio < e.prio;
        }
        bool operator<= (const PQElement& e) const{
            return prio <= e.prio;
        }
    private:
        int prio;
        int id;
};

#endif // PQELEMENT_H
