#pragma once

#include <dxgi1_4.h>
#include <d3d12.h>
#include <wrl/client.h>
#include <vector>
#include <cstdint>
#include <memory>
#include <string>


class DGraphics {
public:
	DGraphics(UINT bufferCount, std::string name, LONG width, LONG height);
	~DGraphics();
private:
	void createWindow(std::string name, LONG width, LONG height);

	void createFactory();
	void getAdapter();
	void createDevice();
	void createCommandQueue();
	void createSwapChain();
	void getSwapChainBuffers();
	void createDescriptoprHeapRtv();
	void createDepthStencilBuffer();
	void createDescriptorHeapDepthStencil();
	void createCommandAllocators();
	void createCommandList();
	void createFences();
	void createFenceEventHandle();

protected:
	void waitFrameComplete(UINT frameIndex);

	std::shared_ptr<class Window> window;   // Window class 

	UINT bufferCount;  //  buffer count 

	Microsoft::WRL::ComPtr<IDXGIFactory4> factory;  /* Factory that use for generate other DXGI objects. */
	Microsoft::WRL::ComPtr<IDXGIAdapter3> adapter;  /* Graphics adapters */
	Microsoft::WRL::ComPtr<ID3D12Device> device;    /* DirectX device */
	Microsoft::WRL::ComPtr<ID3D12CommandQueue> commandQueue;
	Microsoft::WRL::ComPtr<IDXGISwapChain3> swapChain;
	std::vector<Microsoft::WRL::ComPtr<ID3D12Resource>> swapChainBuffers;
	Microsoft::WRL::ComPtr<ID3D12DescriptorHeap> descHeapRtv;  /* DescripterHeap Render target view.  */
	Microsoft::WRL::ComPtr<ID3D12Resource> depthStencilBuffer;
	Microsoft::WRL::ComPtr<ID3D12DescriptorHeap> descHeapDepthStencil;

protected:


	std::vector<Microsoft::WRL::ComPtr<ID3D12CommandAllocator>> commandAllocators;
	Microsoft::WRL::ComPtr<ID3D12GraphicsCommandList> commandList;
	std::vector<Microsoft::WRL::ComPtr<ID3D12Fence>> fences;
	std::vector<UINT64> fenceValues;
	HANDLE fenceEventHandle;
};

