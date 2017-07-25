import java.awt.*;
import java.applet.*;
import java.awt.Event;

public class Example extends Applet {
	Point Lstart, Lend;
	public void paint(Graphics g) {
		
		Font f1 = new Font( "Serif", Font.BOLD, 24);
		g.setFont(f1);
		g.setColor( Color.RED );
		g.drawString("Play with Shapes", 150, 20);
		
		Font f2 = new Font( "Serif", Font.BOLD, 20);
		g.setFont(f2);
		g.setColor( Color.BLACK);
		g.drawString("Square", 20, 70);
		g.drawString("Triangle", 20, 120);
		g.drawString("Rectangle", 20, 170);
		g.drawString("Circle", 20, 220);
		g.drawString("Oval", 20, 270);
		
		g.setColor( Color.blue);
		g.fillRect ( 250, 45, 50, 30);
		g.setColor(Color.green);
		g.fillOval(250,90,50,30);
		g.setColor( Color.RED);
		g.fillRect ( 257, 135, 35, 35);
		g.setColor(Color.GRAY);
		g.fillOval( 255, 190,40,40);
		Polygon poly;
		poly = new Polygon( );
		poly.addPoint(310,280);
		poly.addPoint(250,280);
		poly.addPoint(280,250);
		g.drawPolygon(poly);
		g.setColor(Color.MAGENTA);
		g.fillPolygon(poly);
		g.setColor(Color.ORANGE);
		
		g.drawLine(Lstart.x,Lstart.y,Lend.x,Lend.y);
		
	}
	public boolean mouseDown(Event evt, int x, int y) {
		Lstart=new Point(x,y);
		return true;
	}
	public boolean mouseUp(Event evt, int x, int y) {
		Lend=new Point(x,y);
		repaint();
		return true;
	}
	public void update(Graphics g) {
		paint(g);
	}
}
