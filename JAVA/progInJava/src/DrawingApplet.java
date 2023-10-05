package src;

import java.applet.Applet;
import java.awt.*;
import java.awt.event.*;

public class DrawingApplet extends Applet {
    private Rectangle rectangle;
    private Ellipse circle;
    private DraggableBox draggableBox;
    private TextField inputField;

    public void init() {
        rectangle = new Rectangle(50, 50, 100, 50);
        circle = new Ellipse(200, 50, 50);
        draggableBox = new DraggableBox(100, 200, 80, 80);
        inputField = new TextField(20);

        addMouseListener(new MouseAdapter() {
            public void mousePressed(MouseEvent e) {
                draggableBox.setDraggable(draggableBox.contains(e.getX(), e.getY()));
            }

            public void mouseReleased(MouseEvent e) {
                draggableBox.setDraggable(false);
            }
        });

        addMouseMotionListener(new MouseMotionAdapter() {
            public void mouseDragged(MouseEvent e) {
                if (draggableBox.isDraggable()) {
                    draggableBox.setX(e.getX());
                    draggableBox.setY(e.getY());
                    repaint();
                }
            }
        });

        setLayout(new BorderLayout());
        add(rectangle, BorderLayout.WEST);
        add(circle, BorderLayout.EAST);
        add(draggableBox, BorderLayout.CENTER);
        add(inputField, BorderLayout.SOUTH);
    }

    class Rectangle extends Canvas {
        public Rectangle(int x, int y, int width, int height) {
            setBounds(x, y, width, height);
        }

        public void paint(Graphics g) {
            g.setColor(Color.RED);
            g.fillRect(0, 0, getWidth(), getHeight());
        }
    }

    class Ellipse extends Canvas {
        public Ellipse(int x, int y, int diameter) {
            setBounds(x, y, diameter, diameter);
        }

        public void paint(Graphics g) {
            g.setColor(Color.BLUE);
            g.fillOval(0, 0, getWidth(), getHeight());
        }
    }

    class DraggableBox extends Canvas {
        private int x;
        private int y;
        private int width;
        private int height;
        private boolean draggable;

        public DraggableBox(int x, int y, int width, int height) {
            this.x = x;
            this.y = y;
            this.width = width;
            this.height = height;
            draggable = false;
            setBounds(x, y, width, height);
        }

        public void setX(int x) {
            this.x = x;
        }

        public void setY(int y) {
            this.y = y;
        }

        public void setDraggable(boolean draggable) {
            this.draggable = draggable;
        }

        public boolean isDraggable() {
            return draggable;
        }

        public boolean contains(int x, int y) {
            return (x >= this.x && x <= this.x + width && y >= this.y && y <= this.y + height);
        }

        public void paint(Graphics g) {
            g.setColor(Color.GREEN);
            g.fillRect(0, 0, getWidth(), getHeight());
        }
    }
}

