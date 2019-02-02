template <class T>
class AddElements {
    T element;
public:
    AddElements (T arg)
    {
        element = arg;
    }
    T add(T element2) {
        return element + element2;
    }
};

template <>
class AddElements <string> {
    string element;
public:
    AddElements (string arg) {
        element = arg;
    }
    string concatenate(string &element2) {
      return element + element2;
    }
};