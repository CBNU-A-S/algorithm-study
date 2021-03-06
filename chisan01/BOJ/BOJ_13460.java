package BOJ;

// 백준 골드1 구슬 탈출 2

import java.util.*;

class Board {
    private Object redBall, blueBall, hole;
    char[][] board;

    // left, up, right, down
    final int[] dx = {-1, 0, 1, 0};
    final int[] dy = {0, -1, 0, 1};

    int ret = 987654321;

    // 공이나 구멍
    class Object {
        public int x, y;

        public Object(int x, int y) {
            this.x = x;
            this.y = y;
        }

        public Object(Object copy) {
            this.x = copy.x;
            this.y = copy.y;
        }

        public boolean equals(Object comp) {
            if (this.x != comp.x) return false;
            if (this.y != comp.y) return false;
            return true;
        }

        // '.'이 아닌 블록을 만나기 전까지 이동
        public void move(int dir) {
            char item = board[this.y][this.x];
            board[this.y][this.x] = '.';

            while(0 < this.x && this.x < board.length && 0 < this.y && this.y < board.length - 1) {
                int nextY = this.y + dy[dir];
                int nextX = this.x + dx[dir];
                char nextItem = board[nextY][nextX];
                if(nextItem != '.'){
                    if(nextItem == 'O') {
                        this.x = nextX;
                        this.y = nextY;
                    }
                    break;
                }
                else {
                    this.x = nextX;
                    this.y = nextY;
                }
            }

            board[this.y][this.x] = item;
        }

        public void moveToPosition(Object dest) {
            char item = board[this.y][this.x];
            board[this.y][this.x] = '.';
            this.x = dest.x;
            this.y = dest.y;
            board[this.y][this.x] = item;
        }
    }


    public Board(String[] board) {
        this.board = new char[board.length][board[0].length()];
        for (int y = 0; y < board.length; y++) {
            for (int x = 0; x < board[0].length(); x++) {
                this.board[y][x] = board[y].charAt(x);
                switch (this.board[y][x]) {
                    case 'B' -> blueBall = new Object(x, y);
                    case 'R' -> redBall = new Object(x, y);
                    case 'O' -> hole = new Object(x, y);
                }
            }
        }
    }

    // 이전에 위쪽으로 움직였던 경우에는 다시 아래쪽으로 움직일 필요는 없는듯.
    // 다른 방향들도 마찬가지

    // 빨간 공이랑 파란 공이랑 같은 줄에 있는 경우 예외처리
    // 더 옆에 있는 공부터 먼저 움직여야 한다.

    // x값 감소
    public void moveLeft() {
        if (redBall.y == blueBall.y && redBall.x < blueBall.x) {
            redBall.move(0);
            blueBall.move(0);
        } else {
            blueBall.move(0);
            redBall.move(0);
        }
    }

    // y값 감소
    public void moveUp() {
        if (redBall.x == blueBall.x && redBall.y < blueBall.y) {
            redBall.move(1);
            blueBall.move(1);
        } else {
            blueBall.move(1);
            redBall.move(1);
        }
    }

    // x값 증가
    public void moveRight() {
        if (redBall.y == blueBall.y && redBall.x > blueBall.x) {
            redBall.move(2);
            blueBall.move(2);
        } else {
            blueBall.move(2);
            redBall.move(2);
        }
    }

    // y값 증가
    public void moveDown() {
        if (redBall.x == blueBall.x && redBall.y > blueBall.y) {
            redBall.move(3);
            blueBall.move(3);
        } else {
            blueBall.move(3);
            redBall.move(3);
        }
    }

    public void move(Object prevRedBall, Object prevBlueBall, int time) {
        if (time > 10) {
            return;
        }
        if (prevBlueBall.equals(hole)) {
            return;
        } else if (prevRedBall.equals(hole)) {
            ret = Math.min(ret, time);
            return;
        }

        moveUp();
        move(redBall, blueBall, time + 1);
        redBall.moveToPosition(prevRedBall);
        blueBall.moveToPosition(prevBlueBall);

        moveDown();
        move(redBall, blueBall, time + 1);
        redBall.moveToPosition(prevRedBall);
        blueBall.moveToPosition(prevBlueBall);

        moveLeft();
        move(redBall, blueBall, time + 1);
        redBall.moveToPosition(prevRedBall);
        blueBall.moveToPosition(prevBlueBall);

        moveRight();
        move(redBall, blueBall, time + 1);
        redBall.moveToPosition(prevRedBall);
        blueBall.moveToPosition(prevBlueBall);
    }

    public int minMoveToPopUpOnlyRedBall() {
        move(redBall, blueBall, 0);
        return ret == 987654321 ? -1 : ret; // ret값이 변하지 않았으면 -1 리턴
    }
}

public class BOJ_13460 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int M = sc.nextInt();

        String[] board = new String[N];
        for (int i = 0; i < N; i++) {
            board[i] = sc.next();
        }

        Board B = new Board(board);
        System.out.println(B.minMoveToPopUpOnlyRedBall());
    }
}
