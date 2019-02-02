Complex operator + (const Complex &x, const Complex &y){
    Complex c;
    c.a = x.a + y.a;
    c.b = x.b + y.b;
    return c;
}

ostream& operator<<(ostream& os, const Complex &c){  
    os << c.a << "+i" << c.b;  
    return os;  
}