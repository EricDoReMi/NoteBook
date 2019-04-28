package model;

import java.awt.Color;
import java.awt.Graphics;
import java.util.LinkedList;
import java.util.List;

public class Snake
{
  private LinkedList<Point> body = new LinkedList<Point>();
  private Point head = new Point();
  private List<Point> subbody;
  private String rundirection = "right";

public void setBody(LinkedList<Point> body) {
	this.body = body;
}

public Snake() {
    this.subbody = this.body.subList(0, this.body.size());
  }

  public Snake(LinkedList<Point> body, Point head, List<Point> subbody, String rundirection)
  {
    this.body = body;
    this.head = head;
    this.subbody = subbody;
    this.rundirection = rundirection;
  }

  public String getRundirection() {
    return this.rundirection; }

  public void setRundirection(String rundirection) {
    this.rundirection = rundirection; }

  public LinkedList<Point> getBody() {
    return this.body; }

  public void setBody(List<Point> body2) {
    this.body = ((LinkedList<Point>)body2); }

  public Point getHead() {
    return this.head; }

  public void setHead(Point head) {
    this.head = head; }

  public List<Point> getSubbody() {
    return this.subbody; }

  public void setSubbody(List<Point> subbody) {
    this.subbody = subbody;
  }
  
  //paint方法，用于画出蛇，也就是画出蛇身上的每一个点
  public void paint(Graphics g){
	  for(Point p:body){
		  p.setColor(new Color(0,0,255));
		  p.paint(g);
	  }
  }
}