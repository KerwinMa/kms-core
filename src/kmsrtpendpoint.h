#ifndef __KMS_RTP_END_POINT_H__
#define __KMS_RTP_END_POINT_H__

#include <gio/gio.h>
#include <gst/gst.h>
#include <kmsbasertpendpoint.h>

G_BEGIN_DECLS
/* #defines don't like whitespacey bits */
#define KMS_TYPE_RTP_END_POINT \
  (kms_rtp_end_point_get_type())
#define KMS_RTP_END_POINT(obj) \
  (G_TYPE_CHECK_INSTANCE_CAST((obj),KMS_TYPE_RTP_END_POINT,KmsRtpEndPoint))
#define KMS_RTP_END_POINT_CLASS(klass) \
  (G_TYPE_CHECK_CLASS_CAST((klass),KMS_TYPE_RTP_END_POINT,KmsRtpEndPointClass))
#define KMS_IS_RTP_END_POINT(obj) \
  (G_TYPE_CHECK_INSTANCE_TYPE((obj),KMS_TYPE_RTP_END_POINT))
#define KMS_IS_RTP_END_POINT_CLASS(klass) \
  (G_TYPE_CHECK_CLASS_TYPE((klass),KMS_TYPE_RTP_END_POINT))
#define KMS_RTP_END_POINT_CAST(obj) ((KmsRtpEndPoint*)(obj))
typedef struct _KmsRtpEndPoint KmsRtpEndPoint;
typedef struct _KmsRtpEndPointClass KmsRtpEndPointClass;

#define KMS_RTP_END_POINT_LOCK(elem) \
  (g_rec_mutex_lock (&KMS_RTP_END_POINT_CAST ((elem))->media_mutex))
#define KMS_RTP_END_POINT_UNLOCK(elem) \
  (g_rec_mutex_unlock (&KMS_RTP_END_POINT_CAST ((elem))->media_mutex))

struct _KmsRtpEndPoint
{
  KmsBaseRtpEndPoint parent;

  GSocket *audio_rtp_socket;
  GSocket *audio_rtcp_socket;

  GSocket *video_rtp_socket;
  GSocket *video_rtcp_socket;

  GstElement *audio_rtp_udpsink;
  GstElement *audio_rtcp_udpsink;

  GstElement *video_rtp_udpsink;
  GstElement *video_rtcp_udpsink;
};

struct _KmsRtpEndPointClass
{
  KmsBaseRtpEndPointClass parent_class;
};

GType kms_rtp_end_point_get_type (void);

gboolean kms_rtp_end_point_plugin_init (GstPlugin * plugin);

G_END_DECLS
#endif /* __KMS_RTP_END_POINT_H__ */