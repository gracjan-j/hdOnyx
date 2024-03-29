#pragma once

#include "OnyxRenderer.h"
#include "pxr/pxr.h"
#include "pxr/imaging/hd/renderDelegate.h"
#include "pxr/imaging/hd/resourceRegistry.h"

PXR_NAMESPACE_OPEN_SCOPE


class HdOnyxRenderDelegate final : public HdRenderDelegate
{
public:
    HdOnyxRenderDelegate();
    HdOnyxRenderDelegate(HdRenderSettingsMap const& settingsMap);

    virtual ~HdOnyxRenderDelegate();

    const TfTokenVector &GetSupportedRprimTypes() const override;
    const TfTokenVector &GetSupportedSprimTypes() const override;
    const TfTokenVector &GetSupportedBprimTypes() const override;

    HdResourceRegistrySharedPtr GetResourceRegistry() const override;

    HdRenderPassSharedPtr CreateRenderPass(
        HdRenderIndex *index,
        HdRprimCollection const& collection) override;

    HdInstancer *CreateInstancer(HdSceneDelegate *delegate,
                                         SdfPath const& id) override;
    void DestroyInstancer(HdInstancer *instancer) override;

    HdRprim *CreateRprim(TfToken const& typeId, SdfPath const& rprimId) override;
    HdSprim *CreateSprim(TfToken const& typeId, SdfPath const& sprimId) override;
    HdBprim *CreateBprim(TfToken const& typeId, SdfPath const& bprimId) override;

    void DestroyRprim(HdRprim *rPrim) override;
    void DestroySprim(HdSprim *sprim) override;
    void DestroyBprim(HdBprim *bprim) override;

    HdSprim *CreateFallbackSprim(TfToken const& typeId) override;
    HdBprim *CreateFallbackBprim(TfToken const& typeId) override;

    void CommitResources(HdChangeTracker *tracker) override;

    HdRenderParam *GetRenderParam() const override;

    HdAovDescriptor GetDefaultAovDescriptor(const TfToken& aovName) const override;

private:

    static const TfTokenVector SUPPORTED_RPRIM_TYPES;
    static const TfTokenVector SUPPORTED_SPRIM_TYPES;
    static const TfTokenVector SUPPORTED_BPRIM_TYPES;

    HdResourceRegistrySharedPtr m_ResourceRegistry;
    std::shared_ptr<OnyxRenderer> m_RendererBackend;

    void _Initialize();

    HdOnyxRenderDelegate(const HdOnyxRenderDelegate &) = delete;
    HdOnyxRenderDelegate &operator =(const HdOnyxRenderDelegate &) = delete;
};


PXR_NAMESPACE_CLOSE_SCOPE
