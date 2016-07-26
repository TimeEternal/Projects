public class WaveGesture
{
	private const float WAVE_THRESHOLD = 0.1f;
	private const int WAVE_MOVEMENT_TIMEOUT = 5000;
	private const int LEFT_HAND = 0;
	private const int RIGHT_HAND = 1;
	private const int REQUIRED_ITERATIONS = 4;

	private WaveGestureTracker[, ] _PlayerWaveTracker = new WaveGestureTracker[6, 2];

	public event EventHandler GestureDetected;

	public void Update(Skeleton[] skeletons, long frameTimestamp)
	{
		if (skeletons != null)
		{
			Skeleton skeleton;

			for (int i = 0; i < skeletons.Length; i++)
			{
				skeleton = skeletons[i];

				if (skeleton.TrackingState != SkeletonTrackingState.NotTracked)
				{
					TrackWave(skeleton, true, ref this._PlayerWaveTracker[i, LEFT_HAND], frameTimestamp);
					TrackWave(skeleton, false, ref this._PlayerWaveTracker[i, RIGHT_HAND], frameTimestamp);
				}
				else
				{
					this._PlayerWaveTracker[i, LEFT_HAND].Reset();
					this._PlayerWaveTracker[i, RIGHT_HAND].Reset();
				}
			}
		}
	}
};