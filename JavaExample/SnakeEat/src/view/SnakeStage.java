package view;

import java.awt.Color;
import java.awt.Graphics;
import java.awt.event.KeyAdapter;
import java.awt.event.KeyEvent;
import java.util.Timer;
import java.util.TimerTask;

import javax.swing.JFrame;
import javax.swing.JPanel;

import model.GameModel;

public class SnakeStage extends JPanel{
	private GameModel model = new GameModel();
	private static final int FRAME_WIDTH = 450;
	private static final int FRAME_HEIGHT = 500;
	private static final int COLS = 35;
	private static final int ROWS = 35;
	private static final int FRAME_X = 50;
	private static final int FRAME_Y = 50;
	//舞台的背景颜色了
	private static final Color SNAKE_STAGE_COLOR = new Color(192,192,192);
	
	public SnakeStage(){
		setSize(COLS*model.getCell().POINT_SIZE,ROWS*model.getCell().POINT_SIZE);
	}
	
	//重写paint方法，用于绘制出运行舞台
	public void paint(Graphics g){
		g.setColor(SNAKE_STAGE_COLOR);
		g.fillRect(0,0,getWidth(),getHeight());
		if(model.getCell()!=null){
			model.getCell().paint(g);
		}
		if(model.getSnake()!=null){
			model.getSnake().paint(g);
		}
	}
	
	public void action(){
		model.createStage();
		model.createSnake();
		model.createCell();
		Timer timer = new Timer();
		
		//让蛇动态的跑起来
		timer.schedule(new TimerTask() {
			public void run() {
				model.run(model.getSnake().getRundirection());
				boolean b = model.eat();
				if(b){
					model.createCell();
				}
				repaint();
				if(model.stopGame()){
					this.cancel();
				}
			}
		},500,500);
		
		//为游戏添加监听器
		this.requestFocus();
		this.addKeyListener(new KeyAdapter() {
			public void keyPressed(KeyEvent e) {
				switch(e.getKeyCode()){
				 case KeyEvent.VK_UP:model.run("up"); break;
				 case KeyEvent.VK_DOWN:model.run("down");break;
				 case KeyEvent.VK_RIGHT:model.run("right");break;
				 case KeyEvent.VK_LEFT:model.run("left");break;
				}
				
			}
			
		});
		
	}
	public static void main(String[] args) {
		JFrame jf = new JFrame("贪食蛇");
		SnakeStage stage = new SnakeStage();
		jf.setLayout(null);
		jf.setSize(FRAME_WIDTH, FRAME_HEIGHT);
		stage.setLocation(FRAME_X,FRAME_Y);
		jf.add(stage);
		jf.setLocationRelativeTo(null);
		jf.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		jf.setVisible(true);
		stage.action();
	}
}
