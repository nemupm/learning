import junit.framework.Test;
import junit.framework.TestCase;

/**
 * Created by kiko on 2017/02/05.
 */
public class TestFrame extends TestCase {
    public TestFrame(String name){
        super(name);
    }

    public void testScoreNoThrows(){
        Frame f = new Frame();
        assertEquals(0, f.getScore());
    }

    public void testAddOneThrow(){
        Frame f = new Frame();
        f.add(5);
        assertEquals(5, f.getScore());
    }
}
