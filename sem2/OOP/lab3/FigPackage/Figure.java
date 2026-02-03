package FigPackage;

public abstract class Figure {
    double r, a, v;
    double pi = 3.1428;

    public abstract void calcArea();
    public abstract void calcVolume();
    public abstract void dispArea();
    public abstract void dispVolume();
}
