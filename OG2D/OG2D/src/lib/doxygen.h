
/**
 * @mainpage OG2DLibrary version 0.75
 * 自作OpenGL2Dゲームライブラリ
 * @subsection main_subsec 
 *
 * @ref info
 *
 * @ref readme
 */
 /**
  * @page info 開発実績
  * @subsection main_subsec 開発実績
  *
  * @section main_sec このライブラリを使用して開発したゲーム一覧
  *
  * teamTrickle Trickle
  *
  * https://www.youtube.com/watch?v=0EuPpEUQvic
  */

/**
 * @page readme 既存ゲームライブラリ説明
 * @subsection main_subsec ライブラリ説明
 *
 * @section main_sec Sceneについて
 *
 * Sceneは必ず１つ存在しない限りアプリケーションを終了するようになっている。
 *
 * その中にotherSceneは含まれない。
 *
 * otherSceneはいくつ存在しても問題ないが、存在していてもnowSceneが存在しないならばアプリケーションは終了される。
 *
 * @section main_sec UITaskについて
 *
 * 現在のUITaskの仕様ではGameObjectより後ろに描画することができないため、使用しないこと。
 *
 * @section main_sec Collisionについて
 *
 * CollisionLine,CollisionCapsuleは未完成であり、判定が存在しないものがある
 *
 * @section main_sec ResourceLoadEventについて
 *
 * 現在のShaderの仕様上、Textureより先にSimpleShaderを読み込まなければいけなくなっている。
 */
