##### Program 1: Visual Output in Java
The goal of this program was to garner practice in developing visual based programs.
The program is designed to create three basic shapes, circles, triangles, and rectangles, of random
sizes and positions on a canvas. This is accomplished by creating *classes* in Java.
Since Java is an *object-oriented* language these classes serve as templates that can be used
to construct objects, or in this instance, shapes. By choosing the shapes randomly from 1-3, then 
generating random numbers to fill in the measurements of the shapes, the program can generate any
number of any shapes of any size at any position. The program then moves on to create a canvas upon which
it will paint these shapes. The program proceeds to look at each shape individually. It determines in which order 
the shapes will need to be painted by their assigned priorities of 1-9. Beginning at 1, the program begins to paint
the shapes onto a canvas in their designated colors. For this program, circles are represented in yellow, 
triangles in green, and rectangles in red. By utilizing the dimensions of each shape, the program is able to
correctly draw the shapes to scale of each other. As a finishing touch, the program then calculates the total
area of each shape and displays it in the center of the shape. The end result looks similar to this:
![alt text](https://github.com/Emerixean/Portfolio/blob/Program-1/Lab5D_Complete.png)

The following is the Circle class found within the program.

     package lab5d;

    public class Circle extends Shape {
    private static double radius;
    private double area;

    public Circle (int x , int y , int z, double r){
      super(x,y,z);
      radius = r;}

    public static double getRadius(){
      return radius;}
    
    public double getArea(){
      return area;}
    
     @Override
     public double area(){
      return area = (Math.PI) * (Math.pow(radius, 2));}  

    @Override
    public String toString(){
      return "("+ super.getX()+","+super.getY()+","+super.getZ()+ "): "+"( " + area() + " )";}
    }

The Circle class is an extension of another class called "Shape". This Shape class allows the circles,triangles, and rectangles
to be grouped together under a common category for easier creating and sorting. The circle class, as all the other classes, contains
the methods,subprograms defined by myself, that it needs to perform actions on itself when called upon to do so. This is vital to the functionality of the program as it allows the main portion of the program to manipulate every piece of every shape. The triangles and r ectangles have the same class structures.

Using *JPanels* and *JFrames* as the canvas, the program follows this pattern to paint the circles,triangles, and rectangles:

    if (s instanceof Rectangle) {

                        g.setColor(Color.decode("#B22222")); // Firebrick Red
                       
                        int l = (int)Rectangle.getLength();
                        int w = (int)Rectangle.getWidth();
                        
                        g.fillRect(x - (l/2), y - (w / 2), l, w);

                    }
The program checks each shape to determine what type of shape it is, designates its color, retrieves its dimensions, then draws
the shape. Once the program has done this for ALL of the shapes it has created the end result is displayed for the user to view.
