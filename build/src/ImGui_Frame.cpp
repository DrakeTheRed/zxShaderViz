#include "sppch.h"
#include "ImGui_Frame.h"

#include "Engine.h"

ImGui_Frame::ImGui_Frame()
{
	Init();
}

void ImGui_Frame::Begin()
{
	ImGui_ImplOpenGL3_NewFrame();
	ImGui_ImplGlfw_NewFrame();
	ImGui::NewFrame();
}

void ImGui_Frame::End()
{
	ImGuiIO& io = ImGui::GetIO();
	io.DisplaySize = ImVec2(Engine::GetEngineInstance().GetWindow()->GetWidth(), Engine::GetEngineInstance().GetWindow()->GetHeight());

	ImGui::Render();
	ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
}

void ImGui_Frame::Update(float deltaTime)
{
	ImGuiIO& io = ImGui::GetIO();
	io.DeltaTime = deltaTime > 0.0f ? deltaTime : (float)(1.0f / 60.0f);
}

void ImGui_Frame::Init()
{
	IMGUI_CHECKVERSION();
	ImGui::CreateContext();
	ImGuiIO& io = ImGui::GetIO();
	io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;       // Enable Keyboard Controls

	ImGui::StyleColorsDark();
	SetWindowStyle();

	auto& app = Engine::GetEngineInstance();
	GLFWwindow* window = static_cast<GLFWwindow*>(app.GetWindow()->GetNativeWindow());

	// Setup Platform/Renderer bindings
	ImGui_ImplGlfw_InitForOpenGL(window, true);
	ImGui_ImplOpenGL3_Init("#version 460");
}

void ImGui_Frame::SetWindowStyle()
{
	ImVec4* colors = ImGui::GetStyle().Colors;
	colors[ImGuiCol_TextDisabled] = ImVec4(0.55f, 0.55f, 0.55f, 1.00f);
	colors[ImGuiCol_WindowBg] = ImVec4(0.15f, 0.15f, 0.15f, 0.68f);
	colors[ImGuiCol_FrameBg] = ImVec4(0.29f, 0.29f, 0.29f, 0.54f);
	colors[ImGuiCol_FrameBgHovered] = ImVec4(0.23f, 0.23f, 0.23f, 0.40f);
	colors[ImGuiCol_FrameBgActive] = ImVec4(0.24f, 0.24f, 0.24f, 0.67f);
	colors[ImGuiCol_TitleBgActive] = ImVec4(0.10f, 0.10f, 0.10f, 1.00f);
	colors[ImGuiCol_CheckMark] = ImVec4(0.71f, 0.73f, 0.75f, 1.00f);
	colors[ImGuiCol_SliderGrab] = ImVec4(0.51f, 0.51f, 0.51f, 1.00f);
	colors[ImGuiCol_SliderGrabActive] = ImVec4(0.68f, 0.70f, 0.72f, 1.00f);
	colors[ImGuiCol_Button] = ImVec4(0.70f, 0.70f, 0.70f, 0.40f);
	colors[ImGuiCol_ButtonHovered] = ImVec4(0.22f, 0.23f, 0.23f, 1.00f);
	colors[ImGuiCol_ButtonActive] = ImVec4(0.40f, 0.40f, 0.40f, 1.00f);
	colors[ImGuiCol_Header] = ImVec4(0.22f, 0.22f, 0.22f, 0.31f);
	colors[ImGuiCol_HeaderHovered] = ImVec4(0.13f, 0.13f, 0.13f, 0.80f);
	colors[ImGuiCol_HeaderActive] = ImVec4(0.51f, 0.51f, 0.51f, 1.00f);
	colors[ImGuiCol_SeparatorHovered] = ImVec4(0.53f, 0.53f, 0.53f, 0.78f);
	colors[ImGuiCol_SeparatorActive] = ImVec4(0.30f, 0.30f, 0.30f, 1.00f);
	colors[ImGuiCol_ResizeGrip] = ImVec4(0.24f, 0.24f, 0.24f, 0.20f);
	colors[ImGuiCol_ResizeGripHovered] = ImVec4(0.35f, 0.35f, 0.35f, 0.67f);
	colors[ImGuiCol_ResizeGripActive] = ImVec4(0.24f, 0.24f, 0.24f, 0.95f);
	colors[ImGuiCol_Tab] = ImVec4(0.25f, 0.25f, 0.25f, 0.86f);
	colors[ImGuiCol_TabHovered] = ImVec4(0.21f, 0.21f, 0.21f, 0.80f);
	colors[ImGuiCol_TabActive] = ImVec4(0.57f, 0.57f, 0.57f, 1.00f);
}

void ImGui_Frame::Finalize()
{
	ImGui_ImplOpenGL3_Shutdown();
	ImGui_ImplGlfw_Shutdown();
	ImGui::DestroyContext();
}