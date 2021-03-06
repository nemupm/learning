/**
 * Created by kiko on 2017/02/05.
 */
public class Game {
    private int ball;
    private int firstThrow;
    private int secondThrow;

    private int itsScore = 0;
    private int[] itsThrows = new int[21];
    private int itsCurrentThrow = 0;
    private int itsCurrentFrame = 1;
    private boolean firstThrowInFrame = true;

    public int score(){
        return scoreForFrame(getCurrentFrame() - 1);
    }

    public int getCurrentFrame(){
        return itsCurrentFrame;
    }

    public void add(int pins){
        itsThrows[itsCurrentThrow++]=pins;
        itsScore += pins;
        adjustCurrentFrame(pins);
    }

    private void adjustCurrentFrame(int pins){
        if(firstThrowInFrame == true){
            if(pins == 10)
                itsCurrentFrame++;
            else
                firstThrowInFrame = false;
        }
        else{
            firstThrowInFrame = true;
            itsCurrentFrame++;
        }
        itsCurrentFrame = Math.min(11, itsCurrentFrame);
    }

    public int scoreForFrame(int theFrame){
        ball = 0;
        int score = 0;
        for(int currentFrame = 0;
                currentFrame < theFrame;
                currentFrame++){
            if(strike()) {
                score += 10 + nextTwoBallsForStrike();
                ball++;
            }else if(spare()){
                score += 10 + nextBallForSpare();
                ball += 2;
            }else{
                score += twoBallsInFrame();
                ball += 2;
            }
        }
        return score;
    }

    private boolean strike() {
        return itsThrows[ball] == 10;
    }

    private int nextTwoBallsForStrike(){
        return itsThrows[ball+1] + itsThrows[ball+2];
    }

    private boolean spare(){
        return (itsThrows[ball] + itsThrows[ball+1]) == 10;
    }

    private int nextBallForSpare(){
        return itsThrows[ball+2];
    }

    private int twoBallsInFrame(){
        return itsThrows[ball] + itsThrows[ball+1];
    }
}
