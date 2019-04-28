package model;

import java.awt.Color;
import java.awt.Graphics;

public class Point
{
  private int x;
  private int y;
  public static final int POINT_SIZE=10;
  private Color color=new Color(255,0,0);

public Point()
  {
  }

  public Point(int x, int y)
  {
    this.x = x;
    this.y = y; }

  public int getX() {
    return this.x; }

  public void setX(int x) {
    this.x = x; }

  public int getY() {
    return this.y; }

  public void setY(int y) {
    this.y = y; }
  
  

  public Color getColor() {
	return color;
}

public void setColor(Color color) {
	this.color = color;
}

public String toString() {
    return "[" + this.x + "," + this.y + "]";
  }

  //重写equals方法
  public boolean equals(Object p) {
    if (p == null) return false;
    if (this == p) return true;
    if (!(p instanceof Point)) {
      return false;
    }
    Point p1 = (Point)p;

    return ((p1.getX() == this.x) && (p1.getY() == this.y));
  }
  
//接收graphics参数画出食物
  public void paint(Graphics g){
	  g.setColor(color);
	  g.fill3DRect(x*POINT_SIZE, y*POINT_SIZE,POINT_SIZE,POINT_SIZE, true);
  }
}

