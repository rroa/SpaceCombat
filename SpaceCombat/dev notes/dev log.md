## Space Combat dev log

#### 09/12/2014

4:00AM
---

* Just created the Game class. Doing some formatting and implementation of the main functions that comprise it.
* Got to admit, I'm not happy to be using SDL 1.2, the API feels old. And getting official documentation seems hard.
* Finally found the official docs: http://www.libsdl.org/release/SDL-1.2.15/docs/html/sdlsetvideomode.html. Google kept taking me to the SDL 2.0 wiki.

5:11AM
---

* Made a commit with the new Game class being used from main. Things are starting to roll on...
* Started implementing an abstraction of the SDL Event class.  
  * This will help me override the input events I might want to use in the future.
  * I should wait until I start with the input part, but I want to get it out of the way ASAP. Not sure if my previous implementation of SDL 2.0 will work.

5:43AM
---

* Done with the implementation of my SDLEvent wrapper class. Now the game handles events just the way I want.
* I'll try to go for the stretch and implement the touch event support.

6:11AM
---

* Even though, I implemented the touch handling with the SDL Event wrapper I had to add a #IF macro to the event type check.
  * It turns out that the SDL lib I'm linking against is 1.2 which doesn't have touch support. 
  * I added some code to jump into EMSCRIPTEN in order to test but I'm having some issues with the 'emscripten_set_main_loop' call. 
  * I already changed my Game::OnExecute() function to return 'void' but still it doesn't work.
* I'm tired and I'm gonna call it a night. Maybe in a couple hours I can find out what's happening.
* Pushing to github under the "BasicSDLAppSetup" branch.

6:34AM
---

* Just needed a couple more stabs at the EMSCRIPTEN issue before finally retiring to sleep.
  * I was able to make it compile by placing the loop function at the same level as the function call. 
  * I believe I will be able to go back to my previous structure where Game::OnExecute() returned an int by placing the 
  'emscripten_set_main_loop' function call inside my game class.
  * Right now in its actual form, even though it compiles, it doesn't work properly on the browser the WebGL is not being created properly.
* I'll look at it later.

5:00PM
---

* So, after an unexpected long sleep I'm back at this.
* I decided to leave the EMSCRIPTEN and touch input issue to a side and come back to that later.
* I'm changing my code back to what it was and I'll leave the macro check for EMSCRIPTEN at the SDLEvent wrapper class for now.

