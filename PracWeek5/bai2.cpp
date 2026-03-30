    #include<iostream>
    #include<math.h>

    using namespace std; 

    class point2{
        float x, y; 
        public:
        point2():point2(0,0){}
        point2(float ox, float oy){
            x = ox; 
            y = oy; 
        }
        ~point2(){
            cout << "Deconstructure point2" << "\n"; 
        }
        point2(const point2 &other){
            x = other.x; 
            y = other.y; 
        }
        void display() const{
            cout << "ox = " << x << " " << "oy = " << y << " ";
            cout << "Point not Color" << endl; 
        }
        void set2(float ox, float oy){
            x = ox; y = oy; 
        }
        float get2Ox() const{
            return x; 
        };
        float get2Oy() const{
            return y; 
        }
        bool isDuplicate(float ox, float oy){
            return ox == x && oy == y;  
        }
        void move(float ox, float oy){
            x += ox; 
            y += oy; 
        }
    }; 
    class point3: public point2{
        float z; 
        public:
        point3():point3(0, 0, 0){}
        point3(float ox, float oy, float oz): point2(ox, oy){
            z = oz; 
        }
        ~point3(){
            cout << "Deconstructure point 3" << "\n"; 
        }
        point3(const point3 &other):point2(other){
            z = other.z; 
        }
        void display() const{
            point2::display();
            cout << "oz = " << z << " "; 
            cout << "Point not Color" << endl; 
        }
        void set3(float ox, float oy, float oz){
            point2::set2(ox, oy); 
            z = oz; 
        }
        bool isDuplicate(point3 &other){
            return point2::isDuplicate(other.get2Ox(), other.get2Oy()) && other.z == z; 
        }
        void move(float ox, float oy, float oz){
            point2::move(ox, oy); 
            z += oz; 
        }
        float getZ() const{
            return z; 
        }
        float distance(point3 &other){
            return sqrt((z - other.z)*(z - other.z) 
            + ((other.get2Ox() - this -> get2Ox())*(other.get2Ox() - this -> get2Ox())) 
            + (other.get2Oy() - this -> get2Oy()*(other.get2Oy() - this -> get2Oy()))); 
        }
        point3 midpoint(point3 &other){
            return point3((other.get2Ox() + get2Ox()) / 2,
                        (other.get2Oy() + get2Oy())/2,
                        (other.z + z) / 2); 
        }
        float calPerimeter(point3 &A, point3 &B, point3 &C){
            return A.distance(B) + A.distance(C) + B.distance(C); 
        }
        float calArea(point3 &A, point3 &B, point3 &C){
            float perimeter = (calPerimeter(A, B, C)) / 2; 
            return sqrt(perimeter*(perimeter - A.distance(B))*(perimeter - A.distance(C))*(perimeter - C.distance(B)));  
        }
        friend istream &operator>>(istream &in, point3 &a); 
        friend ostream &operator<<(ostream &out, point3 &a); 
    }; 
    istream &operator>>(istream &in, point3 &a){
        cout << "Enter coordinates: " << endl; 
        float x, y; 
        in >> x; 
        in >> y; 
        a.set2(x, y); 
        in >> a.z; 
        return in; 
    }
    ostream &operator<<(ostream &out, point3 &a){
        cout << "Coordinate is: " << endl; 
        out << a.get2Ox() << " " << a.get2Oy() << " " << a.z << endl;
        return out;  
    }
    class Color{
        float color; 
        public:
        Color():Color(0){}
        Color(float color){
            color = color; 
        }
        ~Color(){
            cout << "DestructureColor\n"; 
        }
        Color(const Color &other){
            this -> color = other.color; 
        }
        void setDefault(){
            color = 0; 
        }
        float getColor() const{
            return color; 
        }
        void changeColor(float col){
            color = col; 
        }
        void setColor(float ox){
            color = ox; 
        }
    }; 
    class ColorPoint: public point2, public Color{
        public:
        ColorPoint():ColorPoint(0, 0, 0){}
        ColorPoint(float ox, float oy, float color):point2(ox, oy), Color(color){}
        ColorPoint(const ColorPoint&other):point2(other), Color(other){}
        ~ColorPoint(){
            cout << "Destructure ColorPoint" << "\n"; 
        }

        void display(){
            cout << Color::getColor() << " " << point2::get2Ox() << " " << point2::get2Oy() << endl; 
        }
        void changeColor(float ox){
            Color::changeColor(ox); 
        }
        void move(float ox, float oy){
            point2::move(ox, oy); 
        }
        void setDefault(){
            Color::setDefault(); 
        }
        float getColor(){
            return Color::getColor(); 
        }
        void getCoordinate(){
            cout << point2::get2Ox() << " " << point2::get2Oy() << endl; 
        }
        friend istream &operator>>(istream &in, ColorPoint &a); 
        friend ostream &operator<<(ostream &out, const ColorPoint &a); 
    }; 
    istream &operator>>(istream &in, ColorPoint &a){
        cout << "Enter ColorPoint" << endl; 
        float ox, oy, color;
        in >> ox >> oy >> color; 
        a.set2(ox, oy); 
        a.setColor(color); 
        return in; 
    }
    ostream &operator<<(ostream &out, const ColorPoint &a){
        out << a.get2Ox() << " " << a.get2Oy() << " " << a.Color::getColor() << endl; 
        return out; 
    }
    class color3C: public point3{
        float color; 
        public:
        color3C():color3C(0, 0, 0, 0){}
        color3C(float ox, float oy, float oz):color3C(ox, oy, oz, 0){}
        color3C(float color):color3C(0, 0, 0, color){}
        color3C(float ox, float oy, float oz, float color):point3(ox, oy, oz){
            this -> color = color; 
        }
        ~color3C(){
            cout << "Deconstructure color" << "\n"; 
        }
        color3C(const color3C& other):point3(other),color(other.color){}
        float getColor(){
            return color; 
        }
        void setColor(float col){
            color = col;
        }
        bool isDuplicate(color3C &other){
            return color == other.color; 
        }
        void display() const{
            point3::display(); 
            cout <<"color = " << color << endl; 
        }
        friend istream &operator>>(istream &in, color3C &a); 
        friend ostream &operator<<(ostream &out, const color3C &a); 
    }; 
    istream &operator>>(istream &in, color3C &a){
        cout << "Enter color for point" << endl; 
        float x, y, z; 
        in >> x >> y >> z; 
        in >> a.color; 
        a.set3(x, y, z); 
        return in; 
    }
    ostream &operator<<(ostream &out,const color3C &a){
        cout << "COlor of Point" << endl; 
        out << a.color << endl; 
        a.point3::display(); 
        return out; 
    }
    class ColorPoint3: public point3, public Color{
        public:
        ColorPoint3():ColorPoint3(0, 0, 0, 0){}
        ColorPoint3(float ox, float oy, float oz):ColorPoint3(ox, oy, oz, 0){}
        ColorPoint3(float ox, float oy, float oz, float color):point3(ox, oy, oz), Color(color){}
        ~ColorPoint3(){
            cout << "Destructure" << endl; 
        }
        ColorPoint3(const ColorPoint3 &other):point3(other), Color(other){}
        float getColor() const{
            return Color::getColor(); 
        }
        float setDefaultColor(){
            Color::setDefault();
        }
        float setColor(float col){
            Color::setColor(col); 
        }
        void display() const{
            cout << point2::get2Ox() << " " << point2::get2Oy() << " " << point3::getZ() << endl; 
        }
        friend istream &operator>>(istream &in, ColorPoint3 &a); 
        friend ostream &operator<<(ostream &out, const ColorPoint3 &a); 
    };
    istream &operator>>(istream &in, ColorPoint3 &a){
        float x, y, z, color; 
        in >> x >> y >> z; 
        a.set3(x, y, z); 
        a.setColor(color); 
        return in; 
    } 
    ostream &operator<<(ostream &out, const ColorPoint3 &a){
        out << a.get2Ox() << " " << a.get2Oy() << " " << a.getColor() << endl; 
    }
    int main(){
        // point3 A; 
        // cin >> A;
        // cout << A;
        // A.move(1, 2, 1); 
        // cout << A;  
        // point3 B; 
        // cin >> B;
        // cout << B; 
        // point3 C; 
        // cin >> C; 
        // cout << C; 
        // cout << C.isDuplicate(B) << endl;
        // cout << A.calArea(A, B, C) << endl;  
        // point3 D = B.midpoint(C); 
        // cout << D; 
        // color3C E(1, 4, 2); 
        // cin >> E; 
        // cout << E; 
        // E.display(); 
        // E.point3::display(); 
        // E.point2::display(); 
        // E.point2::move(1, 1); 
        // E.point2::display(); 
        ColorPoint a;
        cin >> a; 
        cout << a; 
        cout << "Change Color" << endl; 
        a.changeColor(21); 
        cout << a; 
        cout << "Move on" << endl; 
        a.move(1, 3); 
        cout << a; 
        cout << a.getColor();
        a.getCoordinate(); 
        a.setDefault(); 
        cout << a; 
        return 0; 
    }