#include <stdio.h>
#include <raylib.h>

int main(void)
{

    InitWindow(800,600, "raylib testing");
    InitAudioDevice();
    Music sounds = LoadMusicStream("music/music.mp3");
    if (IsAudioDeviceReady() == true ) {
        PlayMusicStream(sounds);
    }
    else {
        printf("audio device not ready");
    }

    Camera camera = { 0 };
    camera.position = (Vector3){0.0f, 10.0f, 10.0f};
    camera.target = (Vector3){0.0f, 0.0f, 0.0f};
    camera.up = (Vector3){0.0f, 1.0f, 0.0f};
    camera.fovy = 60.0f;
    camera.projection = CAMERA_PERSPECTIVE;

    while (!WindowShouldClose()) {
        UpdateMusicStream(sounds);
        BeginDrawing();

        ClearBackground(DARKGRAY);
        BeginMode3D(camera);
         
        DrawCube((Vector3){3.0f, 0.0f, 4.0f}, 2.0f, 5.0f, 2.0f, RED);
        DrawFPS(100, 300);
        DrawText("Music file found!", 300, 150, 32, GREEN);
        EndDrawing();
        EndMode3D();
        if (IsKeyPressed(KEY_SPACE) == true) {
            PauseMusicStream(sounds);
        }
        else if (IsKeyPressedRepeat(KEY_SPACE) == true) {
            ResumeMusicStream(sounds);
        }
        else {
            continue;
        }
    }    

    CloseWindow();
    return 0;
}
