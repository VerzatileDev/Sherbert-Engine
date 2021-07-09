#pragma once
#include <vector>
#include <memory>

class Camera;
class Graphics;
namespace n_SherbRendergraphpass
{
	class RenderGraph;
}

class CameraContainer
{
public:
	void SpawnWindow( Graphics& gfx );
	void Bind( Graphics& gfx );
	void AddCamera( std::shared_ptr<Camera> pCam );
	Camera* operator->();
	~CameraContainer();
	void LinkTechniques( n_SherbRendergraphpass::RenderGraph& rg );
	void Submit( size_t channels ) const;
	Camera& GetActiveCamera();
private:
	Camera& GetControlledCamera();

private:
	std::vector<std::shared_ptr<Camera>> cameras;
	int active = 0;
	int controlled = 0;
};