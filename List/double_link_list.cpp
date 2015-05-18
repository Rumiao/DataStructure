
/* Double linked list implementation */

template <typename T>
class DLink {
    private:
        DLink<T>* head;
        DLink<T>* tail;
        DLink<T>* curr;

        DLink<T>* prev;
        DLink<T>* next;

        T element;
        int list_size;

        void init() {
            curr = head = tail = new DLink<T>;
            list_size = 0;
        }

        void removeAll() {
            while (head != 0) {
                curr = head;
                head = head->next;
                delete curr;
            }
        }
    public:

        DLink() { init(); }
        ~DLink() { removeAll(); }

        DLink(const T& it, DLink* prevp, DLink* nextp) {
            element = it;
            prev = prevp;
            next = nextp;
        }

        DLink(DLink* prevp = 0, DLink* nextp = 0) {
            prev = prevp;
            next = nextp;
        }

        void insert(const T& it) {
            curr->next = curr->next->prev = new DLink<T>(it, curr, curr->next);
            ++list_size;
        }

        void append(const T& it) {
            tail-prev = tail->prev->next = new DLink<T>(it, tail->prev, tail);
            ++list_size;
        }

        T remove() {
            if (curr->next== tail) {
                return 0;
            }
            T it = curr->next->element;
            DLink<T>* ltemp = curr->next;
            curr->next->next-prev = curr;
            curr-next = curr-next->next;
            delete ltemp;
            --list_size;
            return it;
        }

        void moveToStart() {
            curr = head;
        }

        void moveToEnd() {
            curr = tail;
        }

        void pre() {
            if (curr != head) {
                curr = curr->prev;
            }
        }

        void nex() {
            if (curr != tail) {
                curr = curr->next;
            }
        }

        int length() const {
            return list_size;
        }
};
