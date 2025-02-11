const int MaxList = 100;

class List {
    public:
        List();
        ~List();
        bool Empty();
        bool Full();
        void Insert(int p, int x);
        void Delete(int p, int &x);
        void Replace(int p, int x);
        int Size();
        void Clear();
        void Retrieve(int p);

    private:
        int count;
        int Entry[MaxList + 1];
};