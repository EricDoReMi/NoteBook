package model;

import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Random;

public class GameModel
{
  private static Snake snake = new Snake();
  private static Point cell = new Point();

  private static ArrayList<Point> stage = new ArrayList<Point>();



  public static Snake getSnake() {
	return snake;
}

  public static void setSnake(Snake snake) {
	GameModel.snake = snake;
  }

  public static Point getCell() {
	return cell;
  }

  public static void setCell(Point cell) {
	GameModel.cell = cell;
  }

public static ArrayList<Point> getStage() {
	return stage;
}

public static void setStage(ArrayList<Point> stage) {
	GameModel.stage = stage;
}

//创建舞台
public void createStage()
  {
    Point p;
    for (int x = 0; x < 35; ++x) {
      p = new Point();
      p.setX(x);
      p.setY(-1);
      stage.add(p);
    }
    for (int y = 0; y < 35; ++y) {
      p = new Point();
      p.setX(35);
      p.setY(y);
      stage.add(p);
    }
    for (int y = 0; y < 35; ++y) {
      p = new Point();
      p.setX(y);
      p.setY(35);
      stage.add(p);
    }
    for (int y = 0; y < 35; ++y) {
      p = new Point();
      p.setX(-1);
      p.setY(y);
      stage.add(p);
    }

   
  }

//创建蛇
  public void createSnake()
  {
    List<Point> body = new LinkedList<Point>();
    for (int i = 0; i < 12; ++i) {
      Point p = new Point(i, 0);
      body.add(p);
    }
    snake.setBody(body);
    Point p = (Point)((LinkedList<Point>)body).getLast();
    snake.setHead(p);
    snake.setSubbody(snake.getBody().subList(0, snake.getBody().size()));
  }

  //创建食物
  public void createCell()
  {
    Point cell = new Point();
    Random r = new Random();
    cell.setX(r.nextInt(35));
    cell.setY(r.nextInt(35));
    if (snake.getBody().contains(cell)) {
    	return;
    }else{
    	this.cell=cell;
    }
  }

  //让蛇跑
  public void run(String direction)
  {
    Point p;
    Point p1;
    if (("up".equals(direction)) && 
      (!("down".equals(snake.getRundirection())))) {
      snake.setRundirection("up");
      p = snake.getHead();
      p1 = new Point();
      p1.setX(p.getX());
      p1.setY(p.getY() - 1);
      snake.setHead(p1);
      snake.getBody().add(p1);
      snake.getBody().removeFirst();
      snake.setSubbody(snake.getBody().subList(0, snake.getBody().size() - 1));
    }

    if (("left".equals(direction)) && 
      (!("right".equals(snake.getRundirection())))) {
      snake.setRundirection("left");
      p = snake.getHead();
      p1 = new Point();
      p1.setX(p.getX() - 1);
      p1.setY(p.getY());
      snake.setHead(p1);
      snake.getBody().add(p1);
      snake.getBody().removeFirst();
      snake.setSubbody(snake.getBody().subList(0, snake.getBody().size() - 1));
    }

    if (("down".equals(direction)) && 
      (!("up".equals(snake.getRundirection())))) {
      snake.setRundirection("down");
      p = snake.getHead();
      p1 = new Point();
      p1.setX(p.getX());
      p1.setY(p.getY() + 1);
      snake.setHead(p1);
      snake.getBody().add(p1);
      snake.getBody().removeFirst();
      snake.setSubbody(snake.getBody().subList(0, snake.getBody().size() - 1));
    }

    if (("right".equals(direction)) && 
      (!("left".equals(snake.getRundirection())))) {
      snake.setRundirection("right");
      p = snake.getHead();
      p1 = new Point();
      p1.setX(p.getX() + 1);
      p1.setY(p.getY());
      snake.setHead(p1);
      snake.getBody().add(p1);
      snake.getBody().removeFirst();
      snake.setSubbody(snake.getBody().subList(0, snake.getBody().size() - 1));
    }
  }

  //判断蛇吃到食物没有
  //true吃到了食物，false没有吃到食物
  public boolean eat()
  {
	if(snake.getHead().equals(cell)){
		 Point p;
		    Point p1;
		    if ("down".equals(snake.getRundirection())) {
		      p = snake.getHead();
		      p1 = new Point();
		      p1.setX(p.getX());
		      p1.setY(p.getY() + 1);
		      snake.setHead(p1);
		      snake.getBody().add(p1);
		      snake.setSubbody(snake.getBody().subList(0, snake.getBody().size() - 1));
		    }

		    if ("right".equals(snake.getRundirection())) {
		      p = snake.getHead();
		      p1 = new Point();
		      p1.setX(p.getX() + 1);
		      p1.setY(p.getY());
		      snake.setHead(p1);
		      snake.getBody().add(p1);
		      snake.setSubbody(snake.getBody().subList(0, snake.getBody().size() - 1));
		    }

		    if ("up".equals(snake.getRundirection())) {
		      p = snake.getHead();
		      p1 = new Point();
		      p1.setX(p.getX());
		      p1.setY(p.getY() - 1);
		      snake.setHead(p1);
		      snake.getBody().add(p1);
		      snake.setSubbody(snake.getBody().subList(0, snake.getBody().size() - 1));
		    }

		    if ("left".equals(snake.getRundirection())) {
		      p = snake.getHead();
		      p1 = new Point();
		      p1.setX(p.getX() - 1);
		      p1.setY(p.getY());
		      snake.setHead(p1);
		      snake.getBody().add(p1);
		      snake.setSubbody(snake.getBody().subList(0, snake.getBody().size() - 1));
		    }
		    return true;
	}
   
    return false;
  }
  
  //判断蛇是否碰到自己或者墙壁
  //true就停下，false继续
  public boolean stopGame(){
	  if(snake.getSubbody().contains(snake.getHead())||stage.contains(snake.getHead())){
		  return true;
	  }else{
		  return false;
	  }
  }
}