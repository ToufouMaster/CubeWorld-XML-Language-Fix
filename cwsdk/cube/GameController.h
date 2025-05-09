#pragma once


#include "../msvc_bincompat.h"
#include "../Matrix4x4.h"
#include "../plasma/Node.h"
#include "World.h"
#include "WorldMap.h"
#include "Chunk.h"

namespace cube {
	struct Creature;
	struct ChatWidget;
	struct OptionsWidget;

	struct GameController
	{
		void *vtable;

		// Not an actual struct in the client, just used for organization in cwsdk.
		struct {
			uint8_t lmb_down;
			uint8_t rmb_down;
			uint8_t num_key_1;
			uint8_t num_key_2;
			uint8_t num_key_3;
			uint8_t num_key_4;
			uint8_t mmb_down;
			uint8_t key_W;
			uint8_t key_S;
			uint8_t key_A;
			uint8_t key_D;
			uint8_t key_R;
			uint8_t key_T;
			uint8_t key_E;
			uint8_t key_space;
			uint8_t key_ctrl;
			uint8_t key_shift1;
			uint8_t key_shift2;
			uint8_t field_16;
			uint8_t key_Q;
			uint8_t field_18;
			uint8_t VKEYS_DOWN[256];
			uint8_t lmb_down_1;
			uint8_t rmb_down_1;
			uint8_t mmb_down_1;
		} input;

		uint32_t window_width;
		uint32_t window_height;
		uint32_t field_124;
		uint32_t field_128;
		uint32_t field_12C;
		uint32_t field_130;
		LPDIRECT3DDEVICE9 SomeDirect3DDevice9;
		uint32_t field_138;
		uint32_t field_13C;
		Vector3<int64_t> camera_position;
		Vector3<int64_t> camera_focus_position;
		uint32_t option_fullscreen;
		uint32_t option_res_width;
		uint32_t option_res_height;
		uint32_t option_antialiasing_level;
		uint32_t option_render_distance;
		uint32_t option_sound_fx_volume;
		uint32_t option_music_volume;
		uint32_t option_camera_speed;
		uint32_t option_camera_smoothness;
		uint32_t option_invert_y;
		uint32_t option_language;
		uint32_t milliseconds_per_frame;
		uint32_t shutdown;
		Vector3<float> camera_current_rotation;
		Vector3<float> camera_target_rotation;
		uint32_t current_zoom_1;
		uint32_t target_zoom;
		uint32_t unk_camera_float_current;
		uint32_t unk_camera_float_target;
		uint32_t current_zoom_2;
		uint32_t target_fog_dist;
		uint32_t current_fog_dist;
		uint64_t field_1D8;
		uint64_t field_1E0;
		uint32_t field_1E8;
		Matrix4x4 cam_matrix_1;
		Matrix4x4 cam_matrix_2;
		Matrix4x4 cam_matrix_3;
		uint32_t some_chunk_x;
		uint32_t some_chunk_y;
		uint32_t field_2B4;
		uint32_t field_2B8;
		uint32_t chunk_x_matches_commandsmods;
		uint32_t chunk_y_matches_commandsmods;
		uint32_t field_2C4;
		uint32_t field_2C8;
		uint32_t field_2CC;
		uint32_t field_2D0;
		uint32_t field_2D4;
		uint32_t field_2D8;
		uint32_t chunk_count_to_be_sqaured;
		Chunk *chunks;
		World world;
		CubeShader* shader;
		uint8_t should_update_world_maybe;
		uint8_t ConnectedToServer;
		uint32_t field_800588;
		uint32_t field_80058C;
		uint32_t field_800590;
		uint32_t field_800594;
		MSVCBinCompat::string command_line_arg_1;
		uint8_t chunk_generation_enabled;
		uint8_t field_8005B1;
		uint8_t field_8005B2;
		uint8_t field_8005B3;
		uint32_t field_8005B4;
		_RTL_CRITICAL_SECTION unk_critical_section_1;
		_RTL_CRITICAL_SECTION unk_critical_section_2;
		_RTL_CRITICAL_SECTION unk_critical_section_3;
		_RTL_CRITICAL_SECTION chunk_deletion_critical_section;
		_RTL_CRITICAL_SECTION unk_critical_section_5;
		uint32_t field_800630;
		uint32_t field_800634;
		uint32_t field_800638;
		uint32_t field_80063C;
		uint32_t field_800640;
		uint32_t field_800644;
		uint32_t field_800648;
		uint32_t field_80064C;
		uint32_t field_800650;
		uint32_t field_800654;
		uint32_t field_800658;
		uint32_t field_80065C;
		uint32_t field_800660;
		uint32_t field_800664;
		uint32_t field_800668;
		uint32_t field_80066C;
		uint32_t field_800670;
		uint32_t field_800674;
		uint32_t field_800678;
		uint32_t field_80067C;
		uint32_t field_800680;
		uint32_t field_800684;
		uint32_t field_800688;
		uint32_t field_80068C;
		uint32_t field_800690;
		uint32_t field_800694;
		uint32_t field_800698;
		uint32_t field_80069C;
		uint32_t field_8006A0;
		uint32_t field_8006A4;
		uint32_t field_8006A8;
		uint32_t field_8006AC;
		uint32_t field_8006B0;
		uint32_t field_8006B4;
		uint32_t field_8006B8;
		uint32_t field_8006BC;
		uint32_t field_8006C0;
		uint32_t field_8006C4;
		uint32_t field_8006C8;
		uint32_t some_socket;
		Creature *local_player;
		uint32_t field_8006D4;
		uint32_t field_8006D8;
		uint32_t field_8006DC;
		uint32_t field_8006E0;
		uint8_t map_open;
		uint32_t field_8006E8;
		uint32_t field_8006EC;
		uint32_t field_8006F0;
		uint32_t field_8006F4;
		uint32_t field_8006F8;
		uint32_t field_8006FC;
		uint32_t field_800700;
		uint32_t unk_building_related_maybe;
		uint32_t field_800708;
		uint32_t field_80070C;
		uint32_t field_800710;
		uint32_t field_800714;
		uint32_t unk_vec_static_entites_sprites_1;
		uint32_t field_80071C;
		uint32_t field_800720;
		uint32_t unk_vec_static_entites_sprites_2;
		uint32_t field_800728;
		uint32_t field_80072C;
		uint32_t field_800730;
		uint32_t build_cursor_sprite;
		uint32_t field_800738;
		uint32_t field_80073C;
		uint32_t particles_linked_list;
		uint32_t field_800744;
		uint32_t field_800748;
		uint32_t field_80074C;
		uint32_t field_800750;
		uint32_t field_800754;
		uint32_t field_800758;
		STDVector field_80075C;
		uint32_t field_800768;
		uint32_t field_80076C;
		uint32_t field_800770;
		uint32_t field_800774;
		STDVector field_800778;
		STDVector field_800784;
		uint32_t field_800790;
		uint32_t field_800794;
		uint32_t field_800798;
		uint32_t field_80079C;
		uint32_t field_8007A0;
		uint32_t field_8007A4;
		uint32_t field_8007A8;
		uint32_t field_8007AC;
		uint32_t field_8007B0;
		uint8_t toggle_hp_bars;
		uint32_t field_8007B8;
		uint32_t field_8007BC;
		uint32_t field_8007C0;
		uint32_t field_8007C4;
		uint32_t field_8007C8;
		uint32_t field_8007CC;
		uint32_t field_8007D0;
		uint32_t field_8007D4;
		uint32_t field_8007D8;
		uint32_t field_8007DC;
		uint32_t field_8007E0;
		uint32_t field_8007E4;
		uint32_t field_8007E8;
		uint32_t field_8007EC;
		uint32_t field_8007F0;
		uint32_t field_8007F4;
		uint32_t field_8007F8;
		STDVector SkillBarPlasmaNodes;
		STDVector SkillBarCooldownNodes;
		STDVector SkillBar_IDs_Vector;
		uint32_t SkillBar_Image_To_ID_Map;
		uint32_t field_800824;
		uint32_t field_800828;
		uint32_t field_80082C;
		uint32_t field_800830;
		uint32_t field_800834;
		STDVector field_800838;
		STDVector field_800844;
		uint32_t field_800850;
		uint32_t field_800854;
		uint32_t field_800858;
		uint32_t field_80085C;
		uint32_t field_800860;
		uint32_t field_800864;
		uint32_t field_800868;
		uint32_t field_80086C;
		uint32_t field_800870;
		plasma::Node *field_800874;
		uint32_t field_800878;
		uint32_t field_80087C;
		plasma::Node *field_800880;
		uint32_t field_800884;
		plasma::Node *field_800888;
		plasma::Node *field_80088C;
		plasma::Node *field_800890;
		plasma::Node *field_800894;
		plasma::Node *field_800898;
		plasma::Node *F1HelpNode;
		uint32_t field_8008A0;
		uint32_t field_8008A4;
		uint32_t field_8008A8;
		uint32_t field_8008AC;
		uint32_t field_8008B0;
		uint32_t field_8008B4;
		uint32_t field_8008B8;
		plasma::Node *InventoryNode;
		plasma::Node *CraftWeaponsNode;
		plasma::Node *field_8008C4;
		uint32_t field_8008C8;
		uint32_t field_8008CC;
		uint32_t field_8008D0;
		uint32_t field_8008D4;
		uint32_t field_8008D8;
		plasma::Node *field_8008DC;
		uint32_t QuickItemSelectBoxNode;
		uint32_t ItemPreviewNode;
		uint32_t field_8008E8;
		uint32_t field_8008EC;
		uint8_t field_8008F0;
		uint8_t skills_menu_open;
		uint8_t escape_menu_open;
		uint8_t field_8008F3;
		void *VoxelWidget;
		plasma::Node *field_8008F8;
		uint32_t field_8008FC;
		plasma::Node *field_800900;
		uint32_t field_800904;
		uint32_t field_800908;
		void *SkillWidget;
		plasma::Node *GotoOptionsMenuNode;
		uint32_t field_800914;
		uint32_t field_800918;
		uint32_t field_80091C;
		STDVector field_800920;
		STDVector field_80092C;
		uint32_t field_800938;
		plasma::Node *field_80093C;
		uint32_t field_800940;
		uint32_t field_800944;
		uint32_t ObjectiveWidget;
		uint32_t field_80094C;
		uint32_t StatisticsWidget;
		uint32_t InventoryWidget1;
		uint32_t InventoryWidget2;
		uint32_t InventoryWidget3;
		uint32_t CharacterWidget;
		uint32_t field_800964;
		uint32_t field_800968;
		uint32_t field_80096C;
		uint32_t field_800970;
		uint32_t field_800974;
		STDVector field_800978;
		STDVector db_characters_vec;
		uint32_t field_800990;
		uint32_t field_800994;
		uint32_t field_800998;
		uint32_t field_80099C;
		uint32_t field_8009A0;
		uint32_t field_8009A4;
		uint32_t field_8009A8;
		uint32_t field_8009AC;
		uint32_t field_8009B0;
		plasma::Node *field_8009B4;
		uint32_t field_8009B8;
		uint32_t field_8009BC;
		STDVector field_8009C0;
		uint32_t field_8009CC;
		uint32_t field_8009D0;
		uint32_t field_8009D4;
		uint32_t field_8009D8;
		STDVector WorldInfo_vec;
		uint32_t field_8009E8;
		uint32_t field_8009EC;
		uint32_t field_8009F0;
		uint32_t NameErrorNode;
		uint32_t ConnnectionErrorNode;
		OptionsWidget *OptionsWidget;
		plasma::Node *field_800A00;
		uint32_t field_800A04;
		uint32_t field_800A08;
		uint32_t field_800A0C;
		uint32_t field_800A10;
		ChatWidget *ChatWidget;
		uint32_t SpriteWidget;
		uint32_t field_800A1C;
		uint32_t field_800A20;
		uint32_t field_800A24;
		STDVector field_800A28;
		STDVector field_800A34;
		uint8_t select_quick_item_menu_open;
		uint32_t field_800A44;
		uint32_t field_800A48;
		uint32_t field_800A4C;
		uint32_t field_800A50;
		MSVCBinCompat::string gc_worldname;
		uint32_t field_800A6C;
		int64_t interacting_creature_guid;
		uint32_t interacting_pickupable_item_chunk_x;
		uint32_t interacting_pickupable_item_chunk_y;
		uint32_t interacting_pickupable_item_idx;
		uint32_t interacting_static_entity_chunk_x;
		uint32_t interacting_static_entity_chunk_y;
		uint32_t interacting_static_entity_idx;
		Matrix4x4 culling_related_view_frustum_maybe;
		plasma::Node *field_800AD0;
		plasma::Node *field_800AD4;
		plasma::Node *field_800AD8;
		STDVector field_800ADC;
		uint32_t field_800AE8;
		uint32_t field_800AEC;
		uint32_t field_800AF0;
		uint32_t field_800AF4;
		uint32_t field_800AF8;
		uint32_t field_800AFC;
		uint32_t field_800B00;
		uint32_t field_800B04;
		uint32_t field_800B08;
		uint32_t field_800B0C;
		uint32_t field_800B10;
		uint32_t field_800B14;
		uint32_t field_800B18;
		uint32_t field_800B1C;
		uint32_t field_800B20;
		uint32_t field_800B24;
		uint32_t field_800B28;
		uint32_t field_800B2C;
		uint32_t field_800B30;
		uint32_t field_800B34;
		uint32_t field_800B38;
		uint32_t field_800B3C;
		uint32_t field_800B40;
		uint32_t field_800B44;
		uint32_t field_800B48;
		uint32_t field_800B4C;
		uint32_t field_800B50;
		uint32_t field_800B54;
		uint32_t field_800B58;
		uint32_t field_800B5C;
		uint32_t field_800B60;
		uint32_t field_800B64;
		uint32_t field_800B68;
		uint32_t field_800B6C;
		uint32_t field_800B70;
		uint32_t field_800B74;
		uint32_t field_800B78;
		uint32_t field_800B7C;
		uint32_t field_800B80;
		uint32_t field_800B84;
		uint32_t field_800B88;
		uint32_t field_800B8C;
		uint32_t field_800B90;
		uint32_t field_800B94;
		uint32_t field_800B98;
		uint32_t field_800B9C;
		uint32_t field_800BA0;
		uint32_t field_800BA4;
		uint32_t field_800BA8;
		uint32_t field_800BAC;
		uint32_t field_800BB0;
		uint32_t field_800BB4;
		uint32_t field_800BB8;
		uint32_t field_800BBC;
		uint32_t field_800BC0;
		uint32_t field_800BC4;
		uint32_t field_800BC8;
		uint32_t field_800BCC;
		uint32_t field_800BD0;
		uint32_t field_800BD4;
		uint32_t field_800BD8;
		uint32_t field_800BDC;
		uint32_t field_800BE0;
		uint32_t field_800BE4;
		uint32_t field_800BE8;
		uint32_t field_800BEC;
		uint32_t field_800BF0;
		uint32_t field_800BF4;
		uint32_t field_800BF8;
		uint32_t field_800BFC;
		uint32_t field_800C00;
		uint32_t field_800C04;
		uint32_t field_800C08;
		uint32_t field_800C0C;
		uint32_t field_800C10;
		uint32_t field_800C14;
		uint32_t field_800C18;
		uint32_t field_800C1C;
		uint32_t field_800C20;
		uint32_t field_800C24;
		uint32_t field_800C28;
		uint32_t field_800C2C;
		uint32_t field_800C30;
		uint32_t field_800C34;
		uint32_t field_800C38;
		uint32_t field_800C3C;
		uint32_t field_800C40;
		uint32_t field_800C44;
		uint32_t field_800C48;
		uint32_t field_800C4C;
		uint32_t field_800C50;
		uint32_t field_800C54;
		uint32_t field_800C58;
		uint32_t field_800C5C;
		uint32_t field_800C60;
		uint32_t field_800C64;
		uint32_t field_800C68;
		uint32_t field_800C6C;
		uint32_t field_800C70;
		uint32_t field_800C74;
		uint32_t field_800C78;
		uint32_t field_800C7C;
		uint32_t field_800C80;
		uint32_t field_800C84;
		uint32_t field_800C88;
		uint32_t field_800C8C;
		uint32_t field_800C90;
		uint32_t field_800C94;
		uint32_t field_800C98;
		uint32_t field_800C9C;
		uint32_t field_800CA0;
		uint32_t field_800CA4;
		uint32_t field_800CA8;
		uint32_t field_800CAC;
		uint32_t field_800CB0;
		uint32_t field_800CB4;
		uint32_t field_800CB8;
		uint32_t field_800CBC;
		uint32_t field_800CC0;
		uint32_t field_800CC4;
		uint32_t field_800CC8;
		uint32_t field_800CCC;
		uint32_t field_800CD0;
		uint32_t field_800CD4;
		uint32_t field_800CD8;
		uint32_t field_800CDC;
		uint32_t field_800CE0;
		uint32_t field_800CE4;
		uint32_t field_800CE8;
		uint32_t field_800CEC;
		uint32_t field_800CF0;
		uint32_t field_800CF4;
		uint32_t field_800CF8;
		uint32_t field_800CFC;
		uint32_t field_800D00;
		uint32_t field_800D04;
		uint32_t field_800D08;
		uint32_t field_800D0C;
		uint32_t field_800D10;
		uint32_t field_800D14;
		uint32_t field_800D18;
		uint32_t field_800D1C;
		uint32_t field_800D20;
		uint32_t field_800D24;
		uint32_t field_800D28;
		uint32_t field_800D2C;
		uint32_t field_800D30;
		uint32_t field_800D34;
		uint32_t field_800D38;
		uint32_t field_800D3C;
		uint32_t field_800D40;
		WorldMap WorldMap;
		uint32_t field_1000E4C;
		uint32_t field_1000E50;
		uint32_t field_1000E54;
		uint32_t field_1000E58;
		uint32_t field_1000E5C;
		uint32_t field_1000E60;
		uint32_t field_1000E64;
		uint32_t field_1000E68;
		uint32_t field_1000E6C;
		uint32_t field_1000E70;
		uint32_t field_1000E74;
		uint32_t field_1000E78;
		uint32_t field_1000E7C;
		uint32_t field_1000E80;
		uint32_t field_1000E84;
		uint32_t field_1000E88;
		uint32_t field_1000E8C;
		uint32_t field_1000E90;
		uint32_t field_1000E94;
		uint32_t field_1000E98;
		uint32_t field_1000E9C;
		uint32_t field_1000EA0;
		uint32_t field_1000EA4;
		uint32_t field_1000EA8;
		uint32_t field_1000EAC;
		uint32_t field_1000EB0;
		uint32_t field_1000EB4;
		uint32_t field_1000EB8;
		uint32_t field_1000EBC;
		uint32_t field_1000EC0;
		uint32_t field_1000EC4;
		uint32_t field_1000EC8;
		uint32_t field_1000ECC;
		uint32_t field_1000ED0;
		uint32_t field_1000ED4;
		uint32_t field_1000ED8;
		uint32_t field_1000EDC;
		uint32_t field_1000EE0;
		uint32_t field_1000EE4;
		uint32_t field_1000EE8;
		uint32_t field_1000EEC;
		uint32_t field_1000EF0;
		uint32_t field_1000EF4;
		uint32_t field_1000EF8;
		uint32_t field_1000EFC;
		uint32_t field_1000F00;
		uint32_t field_1000F04;
		uint32_t field_1000F08;
		uint32_t field_1000F0C;
		uint32_t field_1000F10;
		uint32_t field_1000F14;
		uint32_t field_1000F18;
		uint32_t field_1000F1C;
		uint32_t field_1000F20;
		uint32_t field_1000F24;
		uint32_t field_1000F28;
		uint32_t field_1000F2C;
		uint32_t field_1000F30;
		uint32_t field_1000F34;
		uint32_t field_1000F38;
		uint32_t field_1000F3C;
		uint32_t field_1000F40;
		uint32_t field_1000F44;
		uint32_t field_1000F48;
		uint32_t field_1000F4C;
		uint32_t field_1000F50;
		uint32_t field_1000F54;
		uint32_t field_1000F58;
		uint32_t field_1000F5C;
		uint32_t field_1000F60;
		uint32_t field_1000F64;
		uint32_t field_1000F68;
		uint32_t field_1000F6C;
		uint32_t field_1000F70;
		uint32_t field_1000F74;
		uint32_t field_1000F78;
		uint32_t field_1000F7C;
		uint32_t field_1000F80;
		uint32_t field_1000F84;
		uint32_t field_1000F88;
		uint32_t field_1000F8C;
		uint32_t field_1000F90;
		uint32_t field_1000F94;
		uint32_t field_1000F98;
		uint32_t field_1000F9C;
		uint32_t field_1000FA0;
		uint32_t field_1000FA4;
		uint32_t field_1000FA8;
		uint32_t field_1000FAC;
		uint32_t field_1000FB0;
		uint32_t field_1000FB4;
		uint32_t field_1000FB8;
		uint32_t field_1000FBC;
		uint32_t field_1000FC0;
		uint32_t field_1000FC4;
		uint32_t field_1000FC8;
		uint32_t field_1000FCC;
		uint32_t field_1000FD0;
		uint32_t field_1000FD4;
		uint32_t field_1000FD8;
		uint32_t field_1000FDC;
		uint32_t field_1000FE0;
		uint32_t field_1000FE4;
		uint32_t field_1000FE8;
		uint32_t field_1000FEC;
		uint32_t field_1000FF0;
		uint32_t field_1000FF4;
		uint32_t field_1000FF8;
		uint32_t field_1000FFC;
		uint32_t field_1001000;
		uint32_t field_1001004;
		uint32_t field_1001008;
		uint32_t field_100100C;
		uint32_t field_1001010;
		uint32_t field_1001014;

		void UpdateChunk(uint32_t x, uint32_t y);
		bool CameraVoxelRaycast(int64_t max_distance_in_blocks, Vector3<int64_t>* out_block, Vector3<int64_t>* out_face);

	};
};